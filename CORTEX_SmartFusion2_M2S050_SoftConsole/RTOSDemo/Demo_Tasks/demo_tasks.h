
#ifndef _DEMO_TASKS_H
#define _DEMO_TASKS_H

#include "pilot/pilot.h"
#include "FreeRTOS.h"
#include "pilot/init.h"
#include "FreeRTOS-Source/include/task.h"
#include<CMSIS/hw_reg_io.h>
//#include<drivers/CoreI2C/core_i2c.h>
#include<drivers/mss_rtc/mss_rtc.h>
#include<drivers/mss_spi/mss_spi.h>
#include<drivers/mss_timer/mss_timer.h>
#include <drivers/mss_gpio/mss_gpio.h>
//#include <drivers/mss_i2c/mss_i2c.h>
#include <drivers/mss_uart/mss_uart.h>
#include <drivers_config/sys_config/sys_config_mss_clocks.h>
//#include <drivers/CoreTimer/core_timer.h>
//#include <drivers/mss_watchdog/mss_watchdog.h>
#include <drivers/mss_nvm/mss_nvm.h>
#include "pilot/get_data.h"
#include "pilot/read.h"
#include "pilot/write.h"
#include "timers.h"
#include "cmds/cmd.h"
#include "memory/memory.h"
#include "memory/SD.h"


//uint8_t prompt_msg[30] =  "\n\r RTOS_Testing :  \0" ;
i2c_instance_t g_core_i2c2;

void uart0_rx_handler();

#define DEFAULT_ZERO_TIMER_PERIOD 10
#define signal (0)
#define signal_one (1)
#define MSS_BAUD_RATE9600 9600
#define MSS_BAUD_RATE115200 115200
#define HK_API_ID 0x1
#define HK_PKT_LENGTH sizeof(pkt_hk_t)
#define HK_PKT_PERIOD 3
#define HK_COLL_RATE 3000
#define PLD_PKT_LENGTH sizeof(pkt_pld_t)
#define PLD_API_ID 0x2
#define PLD_PKT_LENGTH sizeof(pkt_pld_t)
#define PLD_PKT_PERIOD DEFAULT_ZERO_TIMER_PERIOD
#define PLD_COLL_RATE 3000
#define PILOT_REVERSE_BYTE_ORDER(var)	(((var) << 8) | ((var) >> 8))
#define PLD_BLOCK_START 0x13C6EE
#define PLD_BLOCK_END 0x15C12E

//static imu_t imu_struct = {IMU_ADDR, &g_core_i2c5, COREI2C_5_0, I2C_PCLK_DIV_256, 0x15, 0x16, {0x20, 0x60}, 0x28, 0x2A, 0x2C, 0x29, 0x2B, 0x2D, {0x10,0x6A}, 0x18, 0x1A, 0x1C, 0x19, 0x1B, 0x1D };
//static vc_sensor_t vc_struct = {VC1, &g_core_i2c2, COREI2C_2_0, I2C_PCLK_DIV_256, {0,0}, {0,0}, {0,0}};

size_t uart1_irq_size;

#define DAC_ADDR 0x0E
#define ADC_ADDR 0x21
#define QUEUE_SIZE 3
#define NUM_PKTS 2

char c[25];
char argu[25];
uint8_t command_index ;
uint8_t uart0_irq_rx_buffer[3];
uint8_t data[512];
uint8_t data_pld[50];
uint8_t device[256];
uint8_t device_param[256];

TimerHandle_t pkt_timer[NUM_PKTS];
rx_cmd_t* rx_cmd;
//UBaseType_t Num_of_elements = 5;


void demo(void);

 void set_gpio(void* );
 void set_gpio1(void*);


 typedef struct imu_pkt{
	 uint16_t Acc[3];
	 uint16_t Angular_Rate[3];
	 uint16_t imu_temp;
	 uint8_t imu_counter;
 }__attribute__((packed))imu_pkt_t;

 typedef struct vc_pkt{
	 uint16_t Sensor_Board_VC[2];
	 uint16_t CDH_VC[2];
	 uint16_t Comms_VC[2];
	 uint8_t counter;
 }__attribute__((packed))vc_pkt_t;

 typedef struct pkt_hk{
		uint16_t ccsds_p1;
	    uint16_t ccsds_p2;
	    uint16_t ccsds_p3;

	    uint32_t ccsds_s1;
	    uint32_t ccsds_s2;
//	    uint16_t imu_temp;
//	    uint16_t Acc[3];  // X,Y,Z Axis
//	    uint16_t Angular_Rate[3]; //Pitch, Roll, Yaw
//	    uint16_t Sensor_Board_VC[2];
//	    uint16_t CDH_VC[2];
//	    uint16_t Comms_VC[2];
	    uint16_t cmd_cnt;
	    uint16_t cmd_reject_cnt;
		imu_pkt_t imu_pkt;
		vc_pkt_t vc_pkt;

 }__attribute__((packed))pkt_hk_t;

typedef struct pkt_pld{
		uint16_t ccsds_p1;
		uint16_t ccsds_p2;
		uint16_t ccsds_p3;

		uint32_t ccsds_s1;
		uint32_t ccsds_s2;

		uint16_t adc_chx[8];


}__attribute__((packed))pkt_pld_t;

typedef enum pkt_name{
	hk = 0,
	pld,
}pkt_name_t;

typedef struct pkt{

	pkt_name_t pkt_type;

	void * pkt_data;

	uint8_t pkt_size;

}pkt_t;



#endif
