
#include "read.h"
#include "write.h"
#include "Demo/demo.h"

uint16_t acc[3];

//static imu_t imu_struct = {IMU_ADDR, &g_core_i2c5, COREI2C_5_0, I2C_PCLK_DIV_256, 0x15, 0x16, {0x20, 0x60}, 0x28, 0x2A, 0x2C, 0x29, 0x2B, 0x2D, {0x10,0x6A}, 0x18, 0x1A, 0x1C, 0x19, 0x1B, 0x1D };

void* read_command(device_t d, void* command){

	if(d == read_acc){
		uint8_t result = 0,status;



		imu_t* imu_pkt;
		imu_pkt = (imu_t*) command;


		uint8_t rx_buffer[1], rx_buffer_2[1];

		device_t d1 = wimu_ping;
		write_command(d1, command);
//		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
		I2C_read(imu_pkt->g_core_i2c5, IMU_ADDR, rx_buffer, 1, I2C_RELEASE_BUS);
		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
		result+=status;

		device_t d2 = wimu_accz_l;
		write_command(d2, command);
//		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
		I2C_read(imu_pkt->g_core_i2c5, IMU_ADDR, rx_buffer, 1, I2C_RELEASE_BUS);
		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
		result+=status;

		device_t d3 = wimu_accz_h;
		write_command(d3, command);
//		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
		I2C_read(imu_pkt->g_core_i2c5, IMU_ADDR, rx_buffer_2, 1, I2C_RELEASE_BUS);

		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
			result+=status;

			acc[0] = ((rx_buffer_2[0] << 8) | rx_buffer[0]);
			if((acc[0]) > 32768) {
				acc[0] = 65535-acc[0];
			}

		device_t d4 = wimu_accy_l;
		write_command(d4, command);
//		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
		I2C_read(imu_pkt->g_core_i2c5, IMU_ADDR, rx_buffer, 1, I2C_RELEASE_BUS);
		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
		result+=status;

		device_t d5 = wimu_accy_h;
		write_command(d5, command);
//		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
		I2C_read(imu_pkt->g_core_i2c5, IMU_ADDR, rx_buffer_2, 1, I2C_RELEASE_BUS);

		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
			result+=status;

			acc[1] = ((rx_buffer_2[0] << 8) | rx_buffer[0]);
			if((acc[1]) > 32768) {
				acc[1] = 65535-acc[1];
			}


		device_t d6 = wimu_accx_l;
		write_command(d6, command);
//		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
		I2C_read(imu_pkt->g_core_i2c5, IMU_ADDR, rx_buffer, 1, I2C_RELEASE_BUS);
		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
		result+=status;

		device_t d7 = wimu_accx_h;
		write_command(d7, command);
//		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
		I2C_read(imu_pkt->g_core_i2c5, IMU_ADDR, rx_buffer_2, 1, I2C_RELEASE_BUS);

		status = I2C_wait_complete(imu_pkt->g_core_i2c5,I2C_NO_TIMEOUT);
			result+=status;

			acc[2] = ((rx_buffer_2[0] << 8) | rx_buffer[0]);
			if((acc[2]) > 32768) {
				acc[2] = 65535-acc[2];
			}

		return acc;
	}
	else{
//		return 0;
	}
}
