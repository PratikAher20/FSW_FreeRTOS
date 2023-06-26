
#include "write.h"


void write_command(device_t d, void* command){
	imu_t* imu_pkt;
	imu_pkt = (imu_t*) command;
	vc_sensor_t* vc_pkt;
	vc_pkt = (vc_sensor_t* )command;
	i2c_status_t status;
	if(d == wimu_ping){

//		void set_param();
		I2C_write(imu_pkt->g_core_i2c5, IMU_ADDR, imu_pkt->write_CTRL_REG6_XL, 2, I2C_RELEASE_BUS);
		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
	}
	else if(d == wimu_accz_l){

		I2C_write(imu_pkt->g_core_i2c5,  IMU_ADDR, imu_pkt->read_ACC_out_Z_L, 1, I2C_RELEASE_BUS);
		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
	}
	else if(d == wimu_accz_h){

		I2C_write(imu_pkt->g_core_i2c5,  IMU_ADDR, imu_pkt->read_ACC_out_Z_H, 1, I2C_RELEASE_BUS);
		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
	}
	else if(d == wimu_accy_l){

		I2C_write(imu_pkt->g_core_i2c5,  IMU_ADDR, imu_pkt->read_ACC_out_Y_L, 1, I2C_RELEASE_BUS);
		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
	}
	else if(d == wimu_accy_h){

		I2C_write(imu_pkt->g_core_i2c5,  IMU_ADDR, imu_pkt->read_ACC_out_Y_H, 1, I2C_RELEASE_BUS);
		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
	}

	else if(d == wimu_accx_l){

			I2C_write(imu_pkt->g_core_i2c5,  IMU_ADDR, imu_pkt->read_ACC_out_X_L, 1, I2C_RELEASE_BUS);
			status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
		}
	else if(d == wimu_accx_h){

		I2C_write(imu_pkt->g_core_i2c5,  IMU_ADDR, imu_pkt->read_ACC_out_X_H, 1, I2C_RELEASE_BUS);
		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
	}

	else{

	}
}
