//
#include "peripherals.h"
//#include "get_data.h"
#ifndef _DEVICE_H_
#define _DEVICE_H_
//
#define IMU_ADDR 0x6a
#define VC1 0x40
extern i2c_instance_t g_core_i2c5;
extern i2c_instance_t g_core_i2c4;
#define COREI2C_5_0   0x50005000U

typedef struct imu{

	uint8_t serial_address ;   //Mention as constant in excel
	i2c_instance_t* g_core_i2c5;
	addr_t Base_Addr;
	i2c_clock_divider_t clck_speed;
	uint8_t read_temp_L;
	uint8_t read_temp_H;
	uint8_t write_CTRL_REG6_XL[2];
	uint8_t read_ACC_out_X_L[1];
	uint8_t read_ACC_out_Y_L[1];
	uint8_t read_ACC_out_Z_L[1];
	uint8_t read_ACC_out_X_H[1];
	uint8_t read_ACC_out_Y_H[1];
	uint8_t read_ACC_out_Z_H[1];

	uint8_t write_CTRL_REG1_G[2];
	uint8_t read_AV_out_X_L[1];
	uint8_t read_AV_out_Y_L[1];
	uint8_t read_AV_out_Z_L[1];
	uint8_t read_AV_out_X_H[1];
	uint8_t read_AV_out_Y_H[1];
	uint8_t read_AV_out_Z_H[1];


}imu_t;

typedef struct adc{

	uint8_t serial_address;
	i2c_instance_t* g_core_i2c4;
	addr_t Base_Addr;
	i2c_clock_divider_t clck_speed;


}adc_t;

typedef struct imu_data{
	uint16_t acc[3];
}imu_data_t;
//
typedef struct vc_sensor{

	uint8_t serial_address ;
	i2c_instance_t* g_core_i2c2;
	addr_t Base_Addr;
	i2c_clock_divider_t clck_speed;

	uint16_t VC_1[2]; //Sensor_Board_VC
	uint16_t VC_2[2]; //OBC_VC
	uint16_t VC_3[2]; //PSLV_Interface_VC
}vc_sensor_t;
//
//

typedef enum device{
	imu,
	adc,
	wimu_ping,
	wimu_accz_l,
	wimu_accz_h,
	wimu_accy_l,
	wimu_accy_h,
	wimu_accx_l,
	wimu_accx_h,
	read_acc,
	vc_sensor,
	all,
}device_t;

typedef struct function{

	void (*init) (device_t d, void* command); // Will point to the driver functions
	void (*write)(device_t d, void* command);  //Pointer function which points to the commanding function of that device
	void *(*read)(device_t d, void* command); //Pointer Function which will read data from the data receiving function of that device

}function_t;
//
//
//
//
#endif
