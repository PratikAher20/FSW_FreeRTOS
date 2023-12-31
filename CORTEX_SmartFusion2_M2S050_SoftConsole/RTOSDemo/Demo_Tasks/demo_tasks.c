
#include "demo_tasks.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include<stdio.h>
#include "pilot/get_data.h"
#include <osal/osal.h>
#include "pilot/ccsds.h"
#include "FreeRTOS-Source/include/queue.h"
#include "semphr.h"
#include "queue.h"
#include "stream/stream.h"

static imu_t imu_struct = {IMU_ADDR, &g_core_i2c5, COREI2C_5_0, I2C_PCLK_DIV_256, 0x15, 0x16, {0x20, 0x60}, 0x28, 0x2A, 0x2C, 0x29, 0x2B, 0x2D, {0x10,0x6A}, 0x18, 0x1A, 0x1C, 0x19, 0x1B, 0x1D };
static vc_sensor_t vc_struct = {DAC_ADDR, &g_core_i2c2, COREI2C_2_0, I2C_PCLK_DIV_256, {0,0}, {0,0}, {0,0}};

i2c_instance_t g_core_i2c0;
i2c_instance_t g_core_i2c1;
//i2c_instance_t g_core_i2c2;
i2c_instance_t g_core_i2c3;
i2c_instance_t g_core_i2c4;
i2c_instance_t g_core_i2c5;

QueueHandle_t Store_PKT_Queue;
QueueHandle_t Data_PKT_Queue;

BaseType_t hk_task_feed;
BaseType_t feed_get_hk_data;
BaseType_t feed_get_payload_data;
BaseType_t feed_tlm_task;
BaseType_t feed_tlm_sender;
BaseType_t feed_cmd_tsk;
SemaphoreHandle_t xMutex;
uint16_t command_cnt ;
uint16_t command_reject_cnt;

UBaseType_t data_queue_length = 64;
UBaseType_t item_size = 8;


TaskHandle_t uart_irq = NULL;
TaskHandle_t irq_pro = NULL;

TaskHandle_t tlm_tsk_handle;
TaskHandle_t tlm_sender_handle;
TaskHandle_t get_pld_pkt_handle;
TaskHandle_t get_hk_pkt_handle;
TaskHandle_t cmd_tsk;


pkt_hk_t* hk_pkt;
pkt_pld_t* pld_pkt;

uint16_t hk_seq_num = 1;
uint16_t pld_seq_num = 1;

partition_t payload_p, hk_p;


extern mss_i2c_instance_t g_mss_i2c1;

void get_hk_data(void* d){

	UBaseType_t uxPriority = uxTaskPriorityGet(get_pld_pkt_handle);

	if(feed_get_hk_data != pdFAIL){

//		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		uint16_t ax, ay, az;
		uint8_t result = 0, flag;
		uint8_t loss_count = 0;
		uint16_t roll_rate, pitch_rate, yaw_rate;

		hk_pkt = (pkt_hk_t* )data;


		while(1){
			result = get_IMU_acc(&ax, &ay, &az);
//			uint16_t *a;
//			function_t* imu_device = (function_t*) device;
//			imu_t* imu_dev = &imu_struct;
//			imu_device->read = &read_command;
//			a = imu_device->read(read_acc, (void*) imu_dev);
			result = get_IMU_gyro(&roll_rate, &pitch_rate, &yaw_rate);

	//		pkt_hk->HKID = HK_ID;
	//		pkt_hk->length = HK_length;
			hk_pkt->cmd_cnt = command_cnt;
			hk_pkt->cmd_reject_cnt = command_reject_cnt;
			hk_pkt->imu_pkt.Acc[0] = ((ax));
			hk_pkt->imu_pkt.Acc[1] = ((ay));
			hk_pkt->imu_pkt.Acc[2] = ((az));
			hk_pkt->imu_pkt.Angular_Rate[0] = roll_rate;
			hk_pkt->imu_pkt.Angular_Rate[1] = pitch_rate;
			hk_pkt->imu_pkt.Angular_Rate[2] = yaw_rate;

			uint16_t imu_temp;
			result = get_IMU_temp(&imu_temp);

			hk_pkt->imu_pkt.imu_temp = imu_temp;

			hk_pkt->vc_pkt.Sensor_Board_VC[0] = read_bus_voltage(VC1, 1, &flag);
			loss_count+= flag;
			hk_pkt->vc_pkt.CDH_VC[0] = read_bus_voltage( VC1,  2, &flag);
			loss_count+= flag;
			hk_pkt->vc_pkt.Comms_VC[0] = read_bus_voltage( VC1,  3, &flag);
			loss_count+= flag;
			hk_pkt->vc_pkt.Sensor_Board_VC[1] = read_shunt_voltage(VC1, 1, &flag);
			loss_count+= flag;
			hk_pkt->vc_pkt.CDH_VC[1] = read_shunt_voltage( VC1,  2, &flag);
			loss_count+= flag;

			hk_pkt->vc_pkt.Comms_VC[1] = read_shunt_voltage( VC1,  3, &flag);
			loss_count+= flag;

			data[511] = HK_API_ID;
//			xTaskNotifyGive(tlm_tsk_handle);
//			store_data(&hk_p, data);
			vTaskPrioritySet(get_pld_pkt_handle, uxPriority + 1);
			vTask_Delay(HK_COLL_RATE);

		}
	}
}

void get_pld_data(void* d1){

	UBaseType_t uxPriority = uxTaskPriorityGet(NULL);

	if(feed_get_payload_data != pdFAIL){

		uint8_t flag;
//		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		pld_pkt = (pkt_pld_t* )data_pld;
		uint8_t i;
		while(1){
			for(i=0;i<7;i++){
				pld_pkt->adc_chx[i] = get_ADC_value(&g_core_i2c4, ADC_ADDR, i, flag);
			}
			data_pld[49] = PLD_API_ID;
//			xTaskNotifyGive(tlm_tsk_handle);
//			store_data(&payload_p, data_pld);
			vTaskPrioritySet(NULL, uxPriority - 2);
			vTask_Delay(PLD_COLL_RATE);

		}

	}
}


void vGetPktStruct(pkt_name_t pktname, void* pktdata, uint8_t pktsize){

	pkt_t pkt;

	pkt.pkt_type = pktname;
	pkt.pkt_data = pktdata;
	pkt.pkt_size = pktsize;

//	xQueueSend(Data_PKT_Queue, &pkt, 0);

	// Storing the packets
	if(pkt_stream[pktname].rate != 0){
		xQueueSend(Data_PKT_Queue, &pkt , 0);
		vtlm_sender();
	}
	else{
		xQueueSend(Store_PKT_Queue, &pkt, 0);
	}

}

void vtlm_task(TimerHandle_t exp_timer){
	  // Try to generalised this timer callback function. Also combine the tlm_task and the tlm_sender task.
	uint16_t* t_id;
	t_id = (uint16_t* )pvTimerGetTimerID(exp_timer);
//	pkt_stream->pkt_timer_id = (uint16_t*) pvTimerGetTimerID(exp_timer);
//
//	if(pkt_stream->pkt_timer_id == pkt_stream->pkt.pkt_type){
//
//	}

	if(t_id == 0){
		hk_pkt->ccsds_p1 = PILOT_REVERSE_BYTE_ORDER(((ccsds_p1(tlm_pkt_type, HK_API_ID))));
		hk_pkt->ccsds_p2 = PILOT_REVERSE_BYTE_ORDER(((ccsds_p2((hk_seq_num++)))));
		hk_pkt->ccsds_p3 = PILOT_REVERSE_BYTE_ORDER(((ccsds_p3(HK_PKT_LENGTH))));
		hk_pkt->ccsds_s1 = 0;
		hk_pkt->ccsds_s2 = 0;

		vGetPktStruct( hk, (void*) hk_pkt, HK_PKT_LENGTH);
	}
	if(t_id == 1){
		pld_pkt->ccsds_p1 = PILOT_REVERSE_BYTE_ORDER(((ccsds_p1(tlm_pkt_type, PLD_API_ID))));
		pld_pkt->ccsds_p2 = PILOT_REVERSE_BYTE_ORDER(((ccsds_p2(pld_seq_num++))));
		pld_pkt->ccsds_p3 = PILOT_REVERSE_BYTE_ORDER(((ccsds_p3(PLD_PKT_LENGTH))));

		pld_pkt->ccsds_s1 = 0;
		pld_pkt->ccsds_s2 = 0;

		vGetPktStruct(pld, (void* )pld_pkt, PLD_PKT_LENGTH);
	}
	else{

	}
}


void vtlm_sender(void* d){
	// Use this function only as timer callback which will call function that will send the packet according to its rate.

	pkt_t pkt_send;

//	pkt_stream(pkt_send);

	xQueueReceive(Data_PKT_Queue, &pkt_send, portMAX_DELAY);

	MSS_UART_polled_tx(&g_mss_uart0, pkt_send.pkt_data, pkt_send.pkt_size);

//	xQueueReceive(Data_PKT_Queue, &pkt_send, portMAX_DELAY);
//
//
//	MSS_UART_polled_tx(&g_mss_uart0, pkt_send.pkt_data, pkt_send.pkt_size);


}

void get_imu_data(void* data){

	uint8_t imu_counter=0;
	hk_pkt = (pkt_hk_t*) data;
	uint16_t ax, ay, az;
	uint8_t result = 0;
	imu_data_t* a;
    uint16_t roll_rate, pitch_rate, yaw_rate;
//    xSemaphoreTake(xMutex, portMAX_DELAY);
    function_t* imu_ptr = (function_t*) device ;
		imu_t* imu_dev;
		imu_dev = &imu_struct;
		imu_ptr->read = &read_command;
		a = (imu_data_t*) imu_ptr->read(read_acc, (void* )imu_dev);


    while(1){
		result = get_IMU_acc(&ax, &ay, &az);

		result = get_IMU_gyro(&roll_rate, &pitch_rate, &yaw_rate);

//		pkt_hk->HKID = HK_ID;
//		pkt_hk->length = HK_length;

		hk_pkt->imu_pkt.Acc[0] = (a->acc[2]);
		hk_pkt->imu_pkt.Acc[1] = (a->acc[1]);
		hk_pkt->imu_pkt.Acc[2] = (a->acc[0]);
		hk_pkt->imu_pkt.Angular_Rate[0] = roll_rate;
		hk_pkt->imu_pkt.Angular_Rate[1] = pitch_rate;
		hk_pkt->imu_pkt.Angular_Rate[2] = yaw_rate;

		uint16_t imu_temp;
		result = get_IMU_temp(&imu_temp);

		hk_pkt->imu_pkt.imu_temp = imu_temp;
		hk_pkt->imu_pkt.imu_counter = ++imu_counter;
//		vTask_Delay(1000);

		xSemaphoreGive(xMutex);

    }
}
//
void get_vc_data(void* data){
	uint8_t flag;
	uint8_t loss_count = 0;
	uint8_t counter = 0;
//	vc_pkt_t* vc_pkt;
//
//	vc_pkt = (vc_pkt_t* ) data;
	hk_pkt = (pkt_hk_t*) data;
	xSemaphoreTake(xMutex, portMAX_DELAY);
	while(1){
		hk_pkt->vc_pkt.Sensor_Board_VC[0] = read_bus_voltage(VC1, 1, &flag);
		loss_count+= flag;
//		hk_pkt->vc_pkt.CDH_VC[0] = read_bus_voltage( VC1,  2, &flag);
//		loss_count+= flag;
//		hk_pkt->vc_pkt.Comms_VC[0] = read_bus_voltage( VC1,  3, &flag);
//		loss_count+= flag;
//		hk_pkt->vc_pkt.Sensor_Board_VC[1] = read_shunt_voltage(VC1, 1, &flag);
//		loss_count+= flag;
//		hk_pkt->vc_pkt.CDH_VC[1] = read_shunt_voltage( VC1,  2, &flag);
//		loss_count+= flag;
//		hk_pkt->vc_pkt.Comms_VC[1] = read_shunt_voltage( VC1,  3, &flag);
//		loss_count+= flag;
//		hk_pkt->vc_pkt.counter = ++counter;

		xSemaphoreGive(xMutex);
	}
}

void write_DAC(void* nu){

//	uint8_t REF_DATA[3] = {0x38, 0x00, 0x00};
//	uint8_t REF_DATA[2] = {0x00, 0x05};
	uint8_t PWR[3] = {0x20, 0x00, 0x0F};
	uint8_t config[3] = {0x30, 0x00, 0x01};
//	uint8_t PWR = 0x20;
//	uint8_t PWR_DATA[2] = {0x00, 0x11};
//	uint8_t DAC_A[3] = {0x18, 0x00, 0x00};
	uint8_t DAC_A_cmd[3] = {0x04, 0xFF, 0xF0};
	uint8_t sw_clear[3] = {0x28, 0x00, 0x01};
//	uint8_t DAC_A_Data[2] = {0xFF, 0xF0};
//	uint8_t DAC_B_cmd[1] = {0x19};
//	uint8_t DAC_C_cmd[1] = {0x1A};
//	uint8_t DAC_D_cmd[1] = {0x1B};
//	uint8_t tx_buffer[2];
	uint8_t TD[1] = {0xAA};
	uint8_t rx_buffer[2];
	uint8_t tx[1] = {0xAB};
	i2c_status_t status;
//	I2C_write(VC_SENSOR_I2C, DAC_ADDR, REF, 3, I2C_RELEASE_BUS);
//	status = I2C_wait_complete(VC_SENSOR_I2C, I2C_NO_TIMEOUT);

	while(1){
//	I2C_write(VC_SENSOR_I2C, DAC_ADDR, TD, sizeof(TD), I2C_RELEASE_BUS);
//	status = I2C_wait_complete(VC_SENSOR_I2C,I2C_NO_TIMEOUT);

//	I2C_write(VC_SENSOR_I2C,VC1,tx, sizeof(tx),I2C_RELEASE_BUS);

//	taskENTER_CRITICAL();

//	I2C_write(VC_SENSOR_I2C, DAC_ADDR, sw_clear, 3, I2C_RELEASE_BUS);
//	status = I2C_wait_complete(VC_SENSOR_I2C, I2C_NO_TIMEOUT);
//
//	I2C_write(VC_SENSOR_I2C, DAC_ADDR, PWR, 3, I2C_RELEASE_BUS);
//	status = I2C_wait_complete(VC_SENSOR_I2C,I2C_NO_TIMEOUT);
//
//	I2C_write(VC_SENSOR_I2C, DAC_ADDR, REF_DATA, 2, I2C_RELEASE_BUS);
//	status = I2C_wait_complete(VC_SENSOR_I2C, I2C_NO_TIMEOUT);
//
//	I2C_write(VC_SENSOR_I2C, DAC_ADDR, config, 3, I2C_RELEASE_BUS);
//	status = I2C_wait_complete(VC_SENSOR_I2C,I2C_NO_TIMEOUT);

	I2C_write(VC_SENSOR_I2C, DAC_ADDR, DAC_A_cmd, 3, I2C_RELEASE_BUS);
	status = I2C_wait_complete(VC_SENSOR_I2C,I2C_NO_TIMEOUT);
//	I2C_write(VC_SENSOR_I2C, DAC_ADDR, DAC_A_Data, 2, I2C_RELEASE_BUS);
//	status = I2C_wait_complete(VC_SENSOR_I2C,I2C_NO_TIMEOUT);
//	I2C_read(VC_SENSOR_I2C, DAC_ADDR, rx_buffer, 2, I2C_RELEASE_BUS);
//	status = I2C_wait_complete(VC_SENSOR_I2C, I2C_NO_TIMEOUT);

//	taskEXIT_CRITICAL();
//	I2C_write_read(VC_SENSOR_I2C, DAC_ADDR, DAC_A, sizeof(DAC_A), rx_buffer, sizeof(rx_buffer), I2C_RELEASE_BUS );
//	status = I2C_wait_complete(VC_SENSOR_I2C,I2C_NO_TIMEOUT);

//	I2C_read(VC_SENSOR_I2C, DAC_ADDR, rx_buffer, 3, I2C_RELEASE_BUS);
//	status = I2C_wait_complete(VC_SENSOR_I2C,I2C_NO_TIMEOUT);

	}

}


void irq_tsk_func(void* f_param){

	uint32_t ulNotifiedValue;

	while(1){

		xTaskNotifyWait(0x00, 0, &ulNotifiedValue, portMAX_DELAY);
		ulTaskNotifyTake(pdTRUE, 1);
		rx_cmd = (rx_cmd_t* ) f_param;


		if(cmd_valid(rx_cmd)){
			cmd_engine(rx_cmd);
			command_cnt++;
		}
		else{
			command_reject_cnt++;
		}


	}
}

void uart0_rx_handler(mss_uart_instance_t * this_uart){


	uart1_irq_size = MSS_UART_get_rx(this_uart, uart0_irq_rx_buffer, 8);

	BaseType_t xHigherPriorityTaskWoken;
	 xHigherPriorityTaskWoken = pdFALSE;

	 vTaskNotifyGiveFromISR(uart_irq, &xHigherPriorityTaskWoken);

	 portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

}

//static void prvstatsTask(void *pvparameters){
//	TickType_t xLastExecutionTime;
//
//	static signed char cStringBuffer[512];
//	char nxt_line[1];
//	nxt_line[0] = '\n';
//
//	const TickType_t xBlockPeriod = pdMS_TO_TICKS(5000);
//	xLastExecutionTime = xTaskGetTickCount();
//
//	for( ;; )
//	 {
//		 vTaskDelayUntil( &xLastExecutionTime, xBlockPeriod );
//
//
//		 vTaskGetRunTimeStats( cStringBuffer );
//
//
////		 printf( "\nTask\t\tAbs\t\t\t%%\n" );
////		 printf( "-------------------------------------------------------------\n" );
////
////		 printf("%s\n", cStringBuffer );
//
//		 MSS_UART_polled_tx(&g_mss_uart0, (int) &cStringBuffer, sizeof(cStringBuffer));
//		 MSS_UART_polled_tx(&g_mss_uart0, &nxt_line, sizeof(nxt_line));
//	 }
//}



void demo_tasks(void){

		uint8_t REF_DATA[3] = {0x38, 0x00, 0x00};
		uint8_t PWR[3] = {0x20, 0x00, 0x0F};
		uint8_t config[3] = {0x30, 0x00, 0x01};
		uint8_t sw_clear[3] = {0x28, 0x00, 0x01};
		i2c_status_t status;

//		imu_t* imu_struct = (imu_t*) device_param;

		function_t* imu_ptr = (function_t*) device ;
		imu_t* imu_dev;
//		static imu_t imu_struct = {IMU_ADDR, &g_core_i2c5, COREI2C_5_0, I2C_PCLK_DIV_256, 0x15, 0x16, {0x20, 0x60}, 0x28, 0x2A, 0x2C, 0x29, 0x2B, 0x2D, {0x10,0x6A}, 0x18, 0x1A, 0x1C, 0x19, 0x1B, 0x1D };
		imu_dev = &imu_struct;
		imu_ptr->init = &init;
		imu_ptr->init(imu, (void* )imu_dev);

		I2C_init(&g_core_i2c4, COREI2C_4_0, ADC_ADDR, I2C_PCLK_DIV_256); //ADC Initialisation

		function_t* vc_ptr = (function_t*) device ;
		vc_sensor_t* vc_dev;
//		static vc_sensor_t vc_struct = {VC1, &g_core_i2c2, COREI2C_2_0, I2C_PCLK_DIV_256, {0,0}, {0,0}, {0,0}};
		vc_dev = &vc_struct;
		vc_ptr->init = &init;
		vc_ptr->init(vc_sensor, (void* )vc_dev);

		Data_PKT_Queue = xQueueCreate(QUEUE_SIZE, sizeof(pkt_t));  //Common queue for all packets data storage
		Store_PKT_Queue = xQueueCreate(QUEUE_SIZE, sizeof(pkt_t)); // Queue from which the data will be stored to the storage

		set_pktRate(hk, HK_PKT_PERIOD);   //Set all the default packet rate
		set_pktRate(pld, PLD_PKT_PERIOD);

//		SD_Init();
//		initialise_partition(&payload_p,PAYLOAD_BLOCK_INIT,PAYLOAD_BLOCK_END);
//		initialise_partition(&hk_p,HK_BLOCK_INIT,HK_BLOCK_END);

//		I2C_write(VC_SENSOR_I2C, DAC_ADDR, sw_clear, 3, I2C_RELEASE_BUS);
//		status = I2C_wait_complete(VC_SENSOR_I2C, I2C_NO_TIMEOUT);
//
//		I2C_write(VC_SENSOR_I2C, DAC_ADDR, PWR, 3, I2C_RELEASE_BUS);
//		status = I2C_wait_complete(VC_SENSOR_I2C,I2C_NO_TIMEOUT);
//
//		I2C_write(VC_SENSOR_I2C, DAC_ADDR, REF_DATA, 2, I2C_RELEASE_BUS);
//		status = I2C_wait_complete(VC_SENSOR_I2C, I2C_NO_TIMEOUT);
//
//		I2C_write(VC_SENSOR_I2C, DAC_ADDR, config, 3, I2C_RELEASE_BUS);
//		status = I2C_wait_complete(VC_SENSOR_I2C,I2C_NO_TIMEOUT);

//		pkt_timer[1] = xTimerCreate("PLD_Timer", pdMS_TO_TICKS(3000), pdTRUE, (void*)0, vpld_callback);
//		xTimerStart(pkt_timer[1],0);
//		I2C_write(VC_SENSOR_I2C, DAC_ADDR, PWR, 3, I2C_RELEASE_BUS);
//		status = I2C_wait_complete(VC_SENSOR_I2C,I2C_NO_TIMEOUT);
	//
//		I2C_write(VC_SENSOR_I2C, DAC_ADDR, REF, 3, I2C_RELEASE_BUS);
//		status = I2C_wait_complete(VC_SENSOR_I2C, I2C_NO_TIMEOUT);


//		MSS_I2C_init(&g_mss_i2c1, DAC_ADDR, MSS_I2C_PCLK_DIV_256);

//		I2C_write(VC_SENSOR_I2C, DAC_ADDR, REF_DATA, 2, I2C_RELEASE_BUS);
//		status = I2C_wait_complete(VC_SENSOR_I2C, I2C_NO_TIMEOUT);

		NVIC_EnableIRQ(UART0_IRQn);
		NVIC_SetPriority(UART0_IRQn, configMAX_SYSCALL_INTERRUPT_PRIORITY - 1);


		MSS_UART_init(&g_mss_uart0, 9600, MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT);
		MSS_UART_set_rx_handler(&g_mss_uart0, uart0_rx_handler, MSS_UART_FIFO_EIGHT_BYTES);

//		I2C_init(&g_core_i2c5, COREI2C_5_0, DUMMY_I2C_ADDR, I2C_PCLK_DIV_256);
//		I2C_init(&g_core_i2c2, COREI2C_2_0, DUMMY_I2C_ADDR, I2C_PCLK_DIV_256);
//		device_t d1 = imu;
//		device_t d2 = vc_sensor;
//		device_t d3 = all;
////		init(d1);
////		init(d2);
//		init(d3);]
//		device_t d1 = imu;
//		init_demo(imu);
//	 xTaskCreate(get_hk_data, "Hk_data", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
//		pkt_hk_t* hk_pkt;


	 xMutex = xSemaphoreCreateMutex();


//	 xTaskCreate(write_DAC, "DAC", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
//	 xTaskCreate(get_imu_data, "IMU", configMINIMAL_STACK_SIZE, (void*) hk_pkt , 1, NULL);
//	 xTaskCreate(get_vc_data, "VC", configMINIMAL_STACK_SIZE, (void*) hk_pkt , 1, NULL);
//	 xTaskCreate(pktmngr, "Packet", configMINIMAL_STACK_SIZE, (void*) data, 1, NULL);


		feed_get_hk_data = xTaskCreate(get_hk_data, "HK", configMINIMAL_STACK_SIZE, (void*)data , 2, &get_hk_pkt_handle);

		feed_get_payload_data = xTaskCreate(get_pld_data, "Payload", configMINIMAL_STACK_SIZE, (void* )data, 1, &get_pld_pkt_handle);

		xTaskCreate(irq_tsk_func, "uart_irq", configMINIMAL_STACK_SIZE, (void* )uart0_irq_rx_buffer, 3, &uart_irq);

//		feed_cmd_tsk = xTaskCreate(pro_cmd_tsk, "Command", configMINIMAL_STACK_SIZE, NULL, 2, &cmd_tsk);
		uint8_t i;
		for(i=0; i<NUM_PKTS; i++){
			if(pkt_stream[i].rate != DEFAULT_ZERO_TIMER_PERIOD* 1000){
				pkt_timer[i] = xTimerCreate("PKT_Timer", xMsToTicks(pkt_stream[i].rate),pdTRUE, (void* )i, vtlm_task);
	//			vTimerSetTimerID(pkt_timer[i], (void* )i);
				xTimerStart(pkt_timer[i], 0);
			}
			else{
				pkt_timer[i] = xTimerCreate("PKT_Timer", xMsToTicks(pkt_stream[i].rate),pdTRUE, (void* )i, vtlm_task);
				// Not starting the timer which has zero time period. Its time period will be changed when needed.
			}

		}

//		pkt_timer[0] = xTimerCreate("TLM_Task_Timer", pdMS_TO_TICKS(5000),pdTRUE, (void* )0, vtlm_task);
//		xTimerStart(pkt_timer[0], 0);

//		pkt_timer[1] = xTimerCreate("Sender_Timer", pdMS_TO_TICKS(5005), pdTRUE, (void* )0, vtlm_sender);
//		xTimerStart(pkt_timer[1], 0);

//		feed_tlm_task = xTaskCreate(tlm_task, "Telemetry", configMINIMAL_STACK_SIZE, (void*) data, 1, &tlm_tsk_handle);
//		feed_tlm_sender = xTaskCreate(tlm_sender, "TLM_Data_Sender", configMINIMAL_STACK_SIZE, (void*) data, 1, &tlm_sender_handle);


//	 xTaskCreate(print_uart, "UART", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
//		xTaskCreate(print_uart_1, "UART_1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);


//	 xTaskCreate(prvstatsTask, "Stats", configMINIMAL_STACK_SIZE, NULL, 0, NULL);

	vTaskStartScheduler();

}

void FabricIrq0_IRQHandler(void)
{
    I2C_isr(&g_core_i2c0);
}

void FabricIrq1_IRQHandler(void)
{
    I2C_isr(&g_core_i2c1);
}

void FabricIrq2_IRQHandler(void)
{
    I2C_isr(&g_core_i2c2);
}

void FabricIrq3_IRQHandler(void)
{
    I2C_isr(&g_core_i2c3);
}

void FabricIrq4_IRQHandler(void)
{
    I2C_isr(&g_core_i2c4);
}

void FabricIrq5_IRQHandler(void)
{
    I2C_isr(&g_core_i2c5);
}




