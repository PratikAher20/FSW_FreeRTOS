///**
// * @file 	:	pilot.c
// * @author 	:	Srinidhi G, Pratik Aher
// * @brief 	:	This file implements all the functions defined in pilot.h
// * @version :	1.0
// * @date 	:	2023-01-24
// *
// * @copyright Copyright (c) 2023
// *
// */
//
//#include"pilot.h"
//#include "memory.h"
////#define MSS_UART_DATA_READY    ((uint8_t) 0x01)
//uint32_t prev_wait_time;
//uint8_t ADC_Init(i2c_instance_t *i2c_chx,uint8_t address){
//	i2c_status_t status;
//	uint8_t channel = 0;
//	uint8_t return_value = 0;
//	//Write max and min values to DATA HIGH and DATA LOW registers respectively for all channels
//	uint8_t DATA_HIGH[] = {DATA_HIGH_REG(0),DATAHIGH_MAX_H,DATAHIGH_MAX_L};
//	uint8_t DATA_LOW[] = {DATA_LOW_REG(0),DATA_LOW_MIN_H,DATA_LOW_MIN_L};
//	for(;channel <= 3;channel++) {
//		DATA_HIGH[0] = DATA_HIGH_REG(channel);
//		DATA_LOW[0] = DATA_LOW_REG(channel);
//		I2C_write(i2c_chx,address,DATA_HIGH,3,I2C_RELEASE_BUS);
//		status = I2C_wait_complete(i2c_chx, I2C_NO_TIMEOUT);
//		I2C_write(i2c_chx,address,DATA_LOW,3,I2C_RELEASE_BUS);
//		status = I2C_wait_complete(i2c_chx, I2C_NO_TIMEOUT);
//		return_value |= (status << channel);
//	}
//
//	return return_value;
//}
//
//uint16_t get_ADC_value(i2c_instance_t *i2c_chx,uint8_t address,uint8_t chx,uint8_t *flag) {
//	uint8_t adc_read_value[2];
//	uint8_t ch_read[] = {chx};
//	ch_read[0] |= 0x8;
//	ch_read[0] = ch_read[0] << 4;
//	uint8_t status;
//	uint16_t voltage;
//	I2C_write_read(i2c_chx,address,ch_read,1,adc_read_value,2,I2C_RELEASE_BUS);
//	status = I2C_wait_complete(i2c_chx, I2C_NO_TIMEOUT);
//	if(status != 0) {
//		*flag = 1;
//	} else {
//		voltage = (adc_read_value[0] << 8 ) | adc_read_value[1];
//		voltage &= 0x0FFF;
//		*flag = 0;
//	}
//	return voltage;
//}
//
//// Function below would generate the payload packet containing 40 items : -
//
//uint8_t get_thermistor_vals(thermistor_pkt_t *pkt,uint16_t seq_no){
//   pkt->ccsds_p1 = PILOT_REVERSE_BYTE_ORDER((ccsds_p1(tlm_pkt_type, THERMISTOR_API_ID)));
//   pkt->ccsds_p2 = PILOT_REVERSE_BYTE_ORDER((ccsds_p2(seq_no)));
//   pkt->ccsds_p3 = PILOT_REVERSE_BYTE_ORDER((ccsds_p3(THERMISTOR_PKT_LENGTH)));
//
//   uint8_t i = 0,flag;
//   uint8_t loss_count = 0;
//   pkt->data_valid = 0;
//   for(;i<8;i++){
//       pkt->thermistor_set_A[i] = get_ADC_value(&i2c_3, ADC_I2CU1_ADDR, i,&flag);
//       loss_count+=flag;
//       pkt->data_valid |= ((!flag) << (24+i));
//       pkt->thermistor_set_B[i] = get_ADC_value(&i2c_3, ADC_I2CU2_ADDR, i,&flag);
//       loss_count+=flag;
//       pkt->data_valid |= ((!flag) << (16+i));
//       pkt->thermistor_set_C[i] = get_ADC_value(&i2c_5, ADC_I2CU1_ADDR, i,&flag);
//       loss_count+=flag;
//       pkt->data_valid |= ((!flag) << (8+i));
//     }
//
//    return loss_count;
//}
//
//void delay() {
//	timer_instance_t k;
//	TMR_init(&k,CORETIMER_2_0,TMR_ONE_SHOT_MODE,PRESCALER_DIV_1024,150);
//	TMR_start(&k);
//	uint32_t v;
//	while(1) {
//		v = TMR_current_value(&k);
//		if (v<25) {
//			break;
//		}
//	}
//
//}
//uint8_t get_aris_sample(aris_pkt_t *pkt,uint32_t time,uint8_t sample_no) {
//	uint8_t flag,loss_count = 0;
//	pkt->aris_samples[sample_no].collect_time = time;
//	pkt->aris_samples[sample_no].aris_data[0] = get_ADC_value(&i2c_5, ADC_I2CU2_ADDR, 0,&flag);
//	loss_count+=flag;
//	delay();
//	pkt->aris_samples[sample_no].data_valid = 0;
//	pkt->aris_samples[sample_no].data_valid |= (!flag);
//	pkt->aris_samples[sample_no].aris_data[1] = get_ADC_value(&i2c_5, ADC_I2CU2_ADDR, 1,&flag);
//	delay();
//	loss_count+=flag;
//	pkt->aris_samples[sample_no].data_valid |= ((!flag) << 1);
//	pkt->aris_samples[sample_no].aris_data[2] = get_ADC_value(&i2c_5, ADC_I2CU2_ADDR, 2,&flag);
//	loss_count+=flag;
//	pkt->aris_samples[sample_no].data_valid |= ((!flag) << 2);
//	delay();
//	return loss_count;
//}
//
//// Function below will generate the HK Packet containing ___ items;
//
//uint8_t get_hk(hk_pkt_t *hk_pkt, uint16_t seq_no,uint8_t *sd_s) {
//    uint8_t loss_count = 0,flag;
//
//    hk_pkt->ccsds_p1 = PILOT_REVERSE_BYTE_ORDER(((ccsds_p1(tlm_pkt_type, HK_API_ID))));
//    hk_pkt->ccsds_p2 = PILOT_REVERSE_BYTE_ORDER(((ccsds_p2(seq_no))));
//    hk_pkt->ccsds_p3 = PILOT_REVERSE_BYTE_ORDER(((ccsds_p3(HK_PKT_LENGTH))));
//
//    // CDH_Perip_Status
//
//    hk_pkt->CDH_Periph_Status = test_peripherals(sd_s);
//
//
//    //IMU Values: -
//
//   // Acceleration
//    uint16_t ax, ay, az;
//    uint8_t result;
//    result = get_IMU_acc(&ax, &ay, &az);
//    hk_pkt->Acc[0] = ((ax));
//    hk_pkt->Acc[1] = ((ay));
//    hk_pkt->Acc[2] = ((az));
//
//    // Angular values
//    uint16_t w_roll, w_pitch, w_yaw;
//    result  = get_IMU_gyro(&w_roll, &w_pitch, &w_yaw);
//    hk_pkt->Angular_Rate[0] = w_roll;
//    hk_pkt->Angular_Rate[1] = w_pitch;
//    hk_pkt->Angular_Rate[2] = w_yaw;
//
//    //Temperature
//    uint16_t temperature;
//    result = get_IMU_temp(&temperature);
//    hk_pkt->imu_temp = temperature;
//
//    //CDH_VC
//	hk_pkt->Sensor_Board_VC[0] = read_bus_voltage(VC1, 1, &flag);
//	loss_count+= flag;
//	hk_pkt->CDH_VC[0] = read_bus_voltage( VC1,  2, &flag);
//	loss_count+= flag;
//	hk_pkt->Comms_VC[0] = read_bus_voltage( VC1,  3, &flag);
//	loss_count+= flag;
//	hk_pkt->Sensor_Board_VC[1] = read_shunt_voltage(VC1, 1, &flag);
//	loss_count+= flag;
//	hk_pkt->CDH_VC[1] = read_shunt_voltage( VC1,  2, &flag);
//	loss_count+= flag;
//	hk_pkt->Comms_VC[1] = read_shunt_voltage( VC1,  3, &flag);
//	loss_count+= flag;
//
//	if ((((*sd_s) & SD_TESTED) != 0) && (((*sd_s) & SD_INIT_MASK) == 0)) {
//		prev_wait_time <<= 1;
//		if(prev_wait_time > 604800000){
//			prev_wait_time = 600000;
//		}
//	}
//	hk_pkt->sd_prev_wait_time = prev_wait_time;
//
//    hk_pkt->Fletcher_Code  = HK_FLETCHER_CODE;
//
//    return loss_count;
//}
//
//void I2C_Init() {
//	I2C_init(&g_core_i2c1, COREI2C_1_0, DUMMY_I2C_ADDR, I2C_PCLK_DIV_256);
//	I2C_init(&g_core_i2c2, COREI2C_2_0, DUMMY_I2C_ADDR, I2C_PCLK_DIV_256);
//	I2C_init(&g_core_i2c3, COREI2C_3_0, DUMMY_I2C_ADDR, I2C_PCLK_DIV_256);
//	I2C_init(&g_core_i2c4, COREI2C_4_0, DUMMY_I2C_ADDR, I2C_PCLK_DIV_256);
//	I2C_init(&g_core_i2c5, COREI2C_5_0, DUMMY_I2C_ADDR, I2C_PCLK_DIV_256);
//
//}
//
//void GPIO_Init() {
//	MSS_GPIO_init();
//	MSS_GPIO_config(EN_SENSOR_BOARD,MSS_GPIO_OUTPUT_MODE);
//	MSS_GPIO_config(EN_UART,MSS_GPIO_OUTPUT_MODE);
//	MSS_GPIO_config( SD_CARD_GPIO , MSS_GPIO_OUTPUT_MODE );
//	MSS_GPIO_config( TX_INV_EN , MSS_GPIO_OUTPUT_MODE );
//	MSS_GPIO_config( RX_INV_EN , MSS_GPIO_OUTPUT_MODE );
//}
//
//void SPI_Init() {
//	MSS_SPI_init(&g_mss_spi1);
//	MSS_SPI_configure_master_mode(&g_mss_spi1, MSS_SPI_SLAVE_0, MSS_SPI_MODE0, 512, 8);
//}
//
//void Uart_Init() {
//	MSS_UART_init(&g_mss_uart1,MSS_UART_BAUD_2000000,MSS_UART_DATA_8_BITS | MSS_UART_STICK_PARITY_0 | MSS_UART_ONE_STOP_BIT);
//}
//
//uint8_t Pilot_Peripherals_Init() {
//	uint8_t res = 0;
//	SYSREG->WDOG_CR = WDOG_SYSREG_CR_ENABLE_MASK;
//	MSS_WD_init();
//	uint8_t wdg_reset = MSS_WD_timeout_occured();
//    if(wdg_reset)
//    {
//    	res |= WD_RESET;
//        MSS_WD_clear_timeout_event();
//    }
//	MSS_TIM64_init(MSS_TIMER_ONE_SHOT_MODE);
//	MSS_TIM64_load_immediate(0xFFFFFFFF,0xFFFFFFFF);
//	MSS_TIM64_start();
//	GPIO_Init();
//	I2C_Init();
//	Uart_Init();
//	SPI_Init();
//	res |= SD_Init();
//	prev_wait_time = 600000;
//	return res;
//}
//uint8_t Pilot_Init(timer_pkt_t *init_pkt) {
//	uint8_t res;
//	res = Pilot_Peripherals_Init();
//	MSS_GPIO_set_output(EN_SENSOR_BOARD,1);
//	init_pkt->adc_A = ADC_Init(&i2c_3,ADC_I2CU1_ADDR);
//	init_pkt->adc_B = ADC_Init(&i2c_3,ADC_I2CU2_ADDR);
//	init_pkt->adc_C = ADC_Init(&i2c_5,ADC_I2CU1_ADDR);
//	init_pkt->adc_D = ADC_Init(&i2c_5,ADC_I2CU2_ADDR);
//	MSS_GPIO_set_output(TX_INV_EN,1);
//	MSS_GPIO_set_output(RX_INV_EN,1);
//	MSS_GPIO_set_output(EN_UART,0);
//	init_pkt->vc_init = vc_init(VC1);
//	return res;
//}
//
//uint8_t test_peripherals(uint8_t *sd) {
//	uint16_t count = 0;
//	uint8_t ch_read[] = {0x80};
//	uint8_t adc_read_value[2];
//	uint8_t result = 0x00;
//	uint8_t tx[] = {IMU_WHO_AM_I_REG};
//	count = 0;
//	i2c_status_t status;
//	//Testing i2c_3 in cdh
//	while(count < 10) {
//		I2C_write_read(&g_core_i2c1,ADC_I2CU1_ADDR,ch_read,1,adc_read_value,2,I2C_RELEASE_BUS);
//		status = I2C_wait_complete(&g_core_i2c1, I2C_NO_TIMEOUT);
//		if(status == I2C_SUCCESS) {
//			result |= 0x01;
//			break;
//		}
//		count++;
//	}
//	//Testing i2c_5 in cdh
//	count = 0;
//	while(count < 10) {
//		I2C_write_read(&g_core_i2c3,ADC_I2CU1_ADDR,ch_read,1,adc_read_value,2,I2C_RELEASE_BUS);
//		status = I2C_wait_complete(&g_core_i2c3, I2C_NO_TIMEOUT);
//		if(status == I2C_SUCCESS) {
//			result |= 0x02;
//			break;
//		}
//		count++;
//	}
//	//Testing IMU
//	count = 0;
//	while(count < 10) {
//		I2C_write_read(&g_core_i2c5,IMU_ADDR,tx,1,ch_read,1,I2C_RELEASE_BUS);
//		status = I2C_wait_complete(&g_core_i2c5, I2C_NO_TIMEOUT);
//		if((status == I2C_SUCCESS) && (ch_read[0] == 0x68)) {
//			result |= 0x04;
//			break;
//		}
//		count++;
//	}
//
//	//Testing VC sensor I2C
//	count = 0;
//	count = vc_init(VC1);
//	if(count == 0) {
//		result |= 0x08;
//	}
//
//	//Appending the state of the sd card to result
//	result |= (*sd << 4);
//
//	return result;
//}
//
//uint8_t get_IMU_acc(uint16_t *a_x,uint16_t *a_y,uint16_t *a_z) {
//	uint8_t write_CTRL_REG6_XL[2] = {0x20,0x60};
//	uint8_t read_ACC_out_X_L[] = {0x28};
//	uint8_t read_ACC_out_Y_L[] = {0x2A};
//	uint8_t read_ACC_out_Z_L[] = {0x2C};
//	uint8_t read_ACC_out_X_H[] = {0x29};
//	uint8_t read_ACC_out_Y_H[] = {0x2B};
//	uint8_t read_ACC_out_Z_H[] = {0x2D};
//	uint8_t rx_buffer[1],rx_buffer_2[1];
//	uint8_t result = 0,status;
//
//
//	I2C_write_read(&g_core_i2c5,IMU_ADDR,write_CTRL_REG6_XL,2,rx_buffer,
//					1,I2C_RELEASE_BUS);
//	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//	result+=status;
//
//	I2C_write_read(&g_core_i2c5,IMU_ADDR,read_ACC_out_Z_L,1,rx_buffer,
//							1,I2C_RELEASE_BUS);
//
//	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//	result+=status;
//
//	I2C_write_read(&g_core_i2c5,IMU_ADDR,read_ACC_out_Z_H,1,rx_buffer_2,
//							1,I2C_RELEASE_BUS);
//
//	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//	result+=status;
//
//	*a_z = ((rx_buffer_2[0] << 8) | rx_buffer[0]);
//	if((*a_z) > 32768) {
//		*a_z = 65535-*a_z;
//	}
//
//	I2C_write_read(&g_core_i2c5,IMU_ADDR,read_ACC_out_Y_L,1,rx_buffer,
//							1,I2C_RELEASE_BUS);
//
//	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//	result+=status;
//
//	I2C_write_read(&g_core_i2c5,IMU_ADDR,read_ACC_out_Y_H,1,rx_buffer_2,
//							1,I2C_RELEASE_BUS);
//
//	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//	result+=status;
//
//	*a_y = ((rx_buffer_2[0] << 8) | rx_buffer[0]);
//	if((*a_y) > 32768) {
//		*a_y = 65535-*a_y;
//	}
//
//	I2C_write_read(&g_core_i2c5,IMU_ADDR,read_ACC_out_X_L,1,rx_buffer,
//							1,I2C_RELEASE_BUS);
//
//	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//	result+=status;
//
//	I2C_write_read(&g_core_i2c5,IMU_ADDR,read_ACC_out_X_H,1,rx_buffer_2,
//							1,I2C_RELEASE_BUS);
//
//	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//	result+=status;
//
//	*a_x = ((rx_buffer_2[0] << 8) | rx_buffer[0]);
//	if((*a_x) > 32768) {
//		*a_x = 65535-*a_x;
//	}
//
//	return status;
//
//}
//
//uint8_t get_IMU_gyro(uint16_t *roll_rate, uint16_t *pitch_rate,uint16_t *yaw_rate) {
//
//	uint8_t write_CTRL_REG1_G[2] = {0x10,0x6A};
//		uint8_t read_ACC_out_X_L[] = {0x18};
//		uint8_t read_ACC_out_Y_L[] = {0x1A};
//		uint8_t read_ACC_out_Z_L[] = {0x1C};
//		uint8_t read_ACC_out_X_H[] = {0x19};
//		uint8_t read_ACC_out_Y_H[] = {0x1B};
//		uint8_t read_ACC_out_Z_H[] = {0x1D};
//		uint8_t IMU_slave_addr = 0x6a;
//		uint8_t rx_buffer[1],rx_buffer_2[1];
//		uint8_t result = 0,status;
//
//
//		I2C_write_read(&g_core_i2c5,IMU_slave_addr,write_CTRL_REG1_G,2,rx_buffer,
//						1,I2C_RELEASE_BUS);
//		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//		result+=status;
//
//		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_ACC_out_Z_L,1,rx_buffer,
//								1,I2C_RELEASE_BUS);
//
//		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//		result+=status;
//
//		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_ACC_out_Z_H,1,rx_buffer_2,
//								1,I2C_RELEASE_BUS);
//
//		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//		result+=status;
//
//		*roll_rate = ((rx_buffer_2[0] << 8) | rx_buffer[0]);
//
//		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_ACC_out_Y_L,1,rx_buffer,
//								1,I2C_RELEASE_BUS);
//
//		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//		result+=status;
//
//		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_ACC_out_Y_H,1,rx_buffer_2,
//								1,I2C_RELEASE_BUS);
//
//		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//		result+=status;
//
//		*pitch_rate = ((rx_buffer_2[0] << 8) | rx_buffer[0]);
//
//		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_ACC_out_X_L,1,rx_buffer,
//								1,I2C_RELEASE_BUS);
//
//		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//		result+=status;
//
//		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_ACC_out_X_H,1,rx_buffer_2,
//								1,I2C_RELEASE_BUS);
//
//		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//		result+=status;
//
//		*yaw_rate = ((rx_buffer_2[0] << 8) | rx_buffer[0]);
//
//		return status;
//}
//
//void start_sd_timer(uint8_t *sd_state) {
//	MSS_GPIO_set_output(SD_CARD_GPIO,0);
//	*sd_state = 0;
//	uint64_t ph,pl;
//	time_to_count(prev_wait_time,&ph,&pl);
//	TMR_init(&sd_timer,SD_TIMER_BASE_ADDR,TMR_ONE_SHOT_MODE,PRESCALER_DIV_2,pl/2);
//	TMR_enable_int(&sd_timer);
//	TMR_start(&sd_timer);
//}
//
//void time_to_count(uint32_t ms,uint64_t *upper_count,uint64_t *lower_count) {
//    *lower_count = (ms%FULL_SCALE_TIME_MS) * TIMER_COUNT_PER_MS;
//    *upper_count = (ms/FULL_SCALE_TIME_MS);
//}
//
//void envm_init(reset_pkt_t *check_reset,reset_pkt_t *put_reset) {
//	check_reset = (reset_pkt_t *)ENVM_RESET_PKT_ADDR;
//	if(1000 <= check_reset->reset_count){
//		put_reset->reset_count = 0;
//	}
//	if(0 == check_reset->reset_count) {
//		put_reset->ARIS_Read_Pointer = ARIS_BLOCK_INIT;
//		put_reset->ARIS_Write_Pointer = ARIS_BLOCK_INIT;
//		put_reset->HK_Read_Pointer = HK_BLOCK_INIT;
//		put_reset->HK_Write_Pointer = HK_BLOCK_INIT;
//		put_reset->Logs_Read_Pointer = LOGS_BLOCK_INIT;
//		put_reset->Logs_Write_Pointer = LOGS_BLOCK_INIT;
//		put_reset->SD_Test_Read_Pointer = SD_BLOCK_INIT;
//		put_reset->SD_Test_Write_Pointer = SD_BLOCK_INIT;
//		put_reset->Thermistor_Read_Pointer = PAYLOAD_BLOCK_INIT;
//		put_reset->Thermistor_Write_Pointer = PAYLOAD_BLOCK_INIT;
//		put_reset->reset_count = 1;
//	} else {
//		put_reset->ARIS_Read_Pointer = check_reset->ARIS_Read_Pointer;
//		put_reset->ARIS_Write_Pointer = check_reset->ARIS_Write_Pointer;
//		put_reset->HK_Read_Pointer = check_reset->HK_Read_Pointer;
//		put_reset->HK_Write_Pointer = check_reset->HK_Write_Pointer;
//		put_reset->Logs_Read_Pointer = check_reset->Logs_Read_Pointer;
//		put_reset->Logs_Write_Pointer = check_reset->Logs_Write_Pointer;
//		put_reset->SD_Test_Read_Pointer = check_reset->SD_Test_Read_Pointer;
//		put_reset->SD_Test_Write_Pointer = check_reset->SD_Test_Write_Pointer;
//		put_reset->Thermistor_Read_Pointer = check_reset->Thermistor_Read_Pointer;
//		put_reset->Thermistor_Write_Pointer = check_reset->Thermistor_Write_Pointer;
//		put_reset->reset_count = check_reset->reset_count+1;
//	}
//
//	nvm_status_t nvm_status;
//	nvm_status = NVM_write(ENVM_RESET_PKT_ADDR,(const uint8_t *)put_reset,sizeof(reset_pkt_t),NVM_DO_NOT_LOCK_PAGE);
//}
//
//uint8_t get_IMU_temp(uint16_t *temp) {
//
//		uint8_t read_temp_L[] = {0x15};
//		uint8_t read_temp_H[] = {0x16};
//		uint8_t IMU_slave_addr = 0x6a;
//		uint8_t rx_buffer[1],rx_buffer_2[1];
//		i2c_status_t status;
//
//		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_temp_L,1,rx_buffer,
//								1,I2C_RELEASE_BUS);
//
//		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//
//		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_temp_H,1,rx_buffer_2,
//								1,I2C_RELEASE_BUS);
//
//		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
//
//		*temp = (rx_buffer[0]) | (rx_buffer_2[0] << 8);
//
//		return 0;
//
//}
//
//uint16_t make_FLetcher(uint8_t *data,uint16_t len) {
//	uint8_t sumA = 0,sumB = 0,temp = 0;
//	uint8_t i = 0;
//	for(i = 0;i<len;i++) {
//		sumA = (sumA + data[i]) % 255;
//		sumB = (sumB + sumA) % 255;
//	}
//	temp = 255 - ((sumA + sumB) % 255);
//	sumB = 255 - ((sumA + temp) % 255);
//
//	return ((sumB << 8) | temp);
//
//}
//
////size_t
////MSS_UART_get_rx_one
////(
////    mss_uart_instance_t * this_uart,
////    uint8_t * rx_buff
////)
////{
////    size_t rx_size = 0u;
////    uint8_t status = 0u;
////
////
////
////        status = this_uart->hw_reg->LSR;
////        this_uart->status |= status;
////
////        while(((status & MSS_UART_DATA_READY) != 0u))
////        {
////            rx_buff[0] = this_uart->hw_reg->RBR;
////            status = this_uart->hw_reg->LSR;
////            this_uart->status |= status;
////        }
////    return rx_size;
////}
//void FabricIrq0_IRQHandler(void)
//{
//    I2C_isr(&g_core_i2c0);
//}
//
//void FabricIrq1_IRQHandler(void)
//{
//    I2C_isr(&g_core_i2c1);
//}
//
//void FabricIrq2_IRQHandler(void)
//{
//    I2C_isr(&g_core_i2c2);
//}
//
//void FabricIrq3_IRQHandler(void)
//{
//    I2C_isr(&g_core_i2c3);
//}
//
//void FabricIrq4_IRQHandler(void)
//{
//    I2C_isr(&g_core_i2c4);
//}
//
//void FabricIrq5_IRQHandler(void)
//{
//    I2C_isr(&g_core_i2c5);
//}
