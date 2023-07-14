#include "init.h"
#include "get_data.h"

extern i2c_instance_t g_core_i2c5;
extern i2c_instance_t g_core_i2c2;

//void set_param(imu_t* imu_param){
//
//imu_param-> {&g_core_i2c5, COREI2C_5_0, I2C_PCLK_DIV_256, 0x15, 0x16, {0x20, 0x60}, 0x28, 0x2A, 0x2C, 0x29, 0x2B, 0x2D, {0x10,0x6A}, 0x18, 0x1A, 0x1C, 0x19, 0x1B, 0x1D };
//
//}

void init(device_t d, void* command){

	if(d == imu){
		imu_t* imu_pkt;
		imu_pkt = (imu_t*) command;
//		void set_param();
		I2C_init(imu_pkt->g_core_i2c5, imu_pkt->Base_Addr, DUMMY_I2C_ADDR, imu_pkt->clck_speed);
	}
	else if(d == vc_sensor){
		vc_sensor_t* vc_pkt;
		vc_pkt = (vc_sensor_t*) command;
//		MSS_I2C_init(&g_mss_i2c0, vc_pkt->Base_Addr, DUMMY_I2C_ADDR, vc_pkt->clck_speed);
		MSS_I2C_init(&g_mss_i2c0, DAC_ADDR, I2C_PCLK_DIV_256);
	}
	else if(d == all){
		I2C_init(&g_core_i2c5, COREI2C_5_0, DUMMY_I2C_ADDR, I2C_PCLK_DIV_256);
		I2C_init(&g_core_i2c2, COREI2C_2_0, DUMMY_I2C_ADDR, I2C_PCLK_DIV_256);
	}
	else{

	}

}




