
#include "get_data.h"


extern i2c_instance_t g_core_i2c5;
extern i2c_instance_t g_core_i2c2;

uint8_t get_IMU_acc(uint16_t *a_x,uint16_t *a_y,uint16_t *a_z) {
	uint8_t write_CTRL_REG6_XL[2] = {0x20,0x60};
	uint8_t read_ACC_out_X_L[] = {0x28};
	uint8_t read_ACC_out_Y_L[] = {0x2A};
	uint8_t read_ACC_out_Z_L[] = {0x2C};
	uint8_t read_ACC_out_X_H[] = {0x29};
	uint8_t read_ACC_out_Y_H[] = {0x2B};
	uint8_t read_ACC_out_Z_H[] = {0x2D};
	uint8_t rx_buffer[1],rx_buffer_2[1];
	uint8_t result = 0;
	i2c_status_t status;

	I2C_write(&g_core_i2c5, IMU_ADDR, write_CTRL_REG6_XL, 2,I2C_RELEASE_BUS);

	I2C_read(&g_core_i2c5, IMU_ADDR, rx_buffer, 1, I2C_RELEASE_BUS);

//	I2C_write_read(&g_core_i2c5,IMU_ADDR,write_CTRL_REG6_XL,2,rx_buffer,
//					1,I2C_RELEASE_BUS);
	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
	result+=status;


	I2C_write_read(&g_core_i2c5,IMU_ADDR,read_ACC_out_Z_L,1,rx_buffer,
							1,I2C_RELEASE_BUS);

	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
	result+=status;

	I2C_write_read(&g_core_i2c5,IMU_ADDR,read_ACC_out_Z_H,1,rx_buffer_2,
							1,I2C_RELEASE_BUS);

	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
	result+=status;

	*a_z = ((rx_buffer_2[0] << 8) | rx_buffer[0]);
	if((*a_z) > 32768) {
		*a_z = 65535-*a_z;
	}

	I2C_write_read(&g_core_i2c5,IMU_ADDR,read_ACC_out_Y_L,1,rx_buffer,
							1,I2C_RELEASE_BUS);

	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
	result+=status;

	I2C_write_read(&g_core_i2c5,IMU_ADDR,read_ACC_out_Y_H,1,rx_buffer_2,
							1,I2C_RELEASE_BUS);

	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
	result+=status;

	*a_y = ((rx_buffer_2[0] << 8) | rx_buffer[0]);
	if((*a_y) > 32768) {
		*a_y = 65535-*a_y;
	}

	I2C_write_read(&g_core_i2c5,IMU_ADDR,read_ACC_out_X_L,1,rx_buffer,


							1,I2C_RELEASE_BUS);

	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
	result+=status;

	I2C_write_read(&g_core_i2c5,IMU_ADDR,read_ACC_out_X_H,1,rx_buffer_2,
							1,I2C_RELEASE_BUS);

	status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
	result+=status;

	*a_x = ((rx_buffer_2[0] << 8) | rx_buffer[0]);
	if((*a_x) > 32768) {
		*a_x = 65535-*a_x;
	}

	return status;

}

uint8_t get_IMU_gyro(uint16_t *roll_rate, uint16_t *pitch_rate,uint16_t *yaw_rate) {

	uint8_t write_CTRL_REG1_G[2] = {0x10,0x6A};
		uint8_t read_ACC_out_X_L[] = {0x18};
		uint8_t read_ACC_out_Y_L[] = {0x1A};
		uint8_t read_ACC_out_Z_L[] = {0x1C};
		uint8_t read_ACC_out_X_H[] = {0x19};
		uint8_t read_ACC_out_Y_H[] = {0x1B};
		uint8_t read_ACC_out_Z_H[] = {0x1D};
		uint8_t IMU_slave_addr = 0x6a;
		uint8_t rx_buffer[1],rx_buffer_2[1];
		uint8_t result = 0,status;


		I2C_write_read(&g_core_i2c5,IMU_slave_addr,write_CTRL_REG1_G,2,rx_buffer,
						1,I2C_RELEASE_BUS);
		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
		result+=status;

		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_ACC_out_Z_L,1,rx_buffer,
								1,I2C_RELEASE_BUS);

		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
		result+=status;

		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_ACC_out_Z_H,1,rx_buffer_2,
								1,I2C_RELEASE_BUS);

		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
		result+=status;

		*roll_rate = ((rx_buffer_2[0] << 8) | rx_buffer[0]);

		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_ACC_out_Y_L,1,rx_buffer,
								1,I2C_RELEASE_BUS);

		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
		result+=status;

		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_ACC_out_Y_H,1,rx_buffer_2,
								1,I2C_RELEASE_BUS);

		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
		result+=status;

		*pitch_rate = ((rx_buffer_2[0] << 8) | rx_buffer[0]);

		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_ACC_out_X_L,1,rx_buffer,
								1,I2C_RELEASE_BUS);

		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
		result+=status;

		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_ACC_out_X_H,1,rx_buffer_2,
								1,I2C_RELEASE_BUS);

		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);
		result+=status;

		*yaw_rate = ((rx_buffer_2[0] << 8) | rx_buffer[0]);

		return status;
}

uint8_t get_IMU_temp(uint16_t *temp) {

		uint8_t read_temp_L[] = {0x15};
		uint8_t read_temp_H[] = {0x16};
		uint8_t IMU_slave_addr = 0x6a;
		uint8_t rx_buffer[1],rx_buffer_2[1];
		i2c_status_t status;

		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_temp_L,1,rx_buffer,
								1,I2C_RELEASE_BUS);

		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);

		I2C_write_read(&g_core_i2c5,IMU_slave_addr,read_temp_H,1,rx_buffer_2,
								1,I2C_RELEASE_BUS);

		status = I2C_wait_complete(&g_core_i2c5,I2C_NO_TIMEOUT);

		*temp = (rx_buffer[0]) | (rx_buffer_2[0] << 8);

		return 0;

}


//VC sensor data

uint8_t count;
uint16_t init_command;
uint8_t config_reg;
i2c_status_t status;
uint8_t read[2];
uint16_t bvol;
uint8_t vc_write(uint8_t addr, uint8_t *tx, uint8_t tx_size) {
     count = 0;
    while(count < 10) {
        I2C_write(VC_SENSOR_I2C,addr,tx,tx_size,I2C_RELEASE_BUS);
        status = I2C_wait_complete(VC_SENSOR_I2C,I2C_NO_TIMEOUT);
        if(status == I2C_SUCCESS) {
            return 0;
        }
        count++;
    }
    return count;

}

uint8_t vc_read(uint8_t addr, uint8_t *rx, uint8_t rx_size) {
    count = 0;
    while(count < 10) {
        I2C_read(VC_SENSOR_I2C,addr,rx,rx_size,I2C_RELEASE_BUS);
        status = I2C_wait_complete(VC_SENSOR_I2C,I2C_NO_TIMEOUT);
        if(status == I2C_SUCCESS) {
            return 0;
        }
        count++;
    }
    return count;

}

uint8_t vc_read_reg(uint8_t vc_addr, uint8_t reg_addr,uint8_t *rx) {
    if((vc_write(vc_addr,&reg_addr,sizeof(reg_addr))) >= 10) {
        return 1;
    }
    if((vc_read(vc_addr,(uint8_t*)rx,2)) >= 10) {
        return 1;
    }

    return 0;
}

uint8_t vc_write_reg(uint8_t vc_addr, uint8_t reg_addr,uint8_t *tx,uint8_t tx_size) {
    if((vc_write(vc_addr,&reg_addr,sizeof(reg_addr))) >= 10) {
        return 1;
    }
    if((vc_write(vc_addr,(uint8_t*)tx,tx_size)) >= 10) {
        return 1;
    }

    return 0;
}

uint8_t vc_init(uint8_t addr) {
	init_command = VC_INIT_CMD;
	config_reg = VC_CONFIG_REG;
    if(vc_write(addr,&config_reg,sizeof(config_reg)) >= 10) {
        return 1;
    }
    if(vc_write(addr,(uint8_t*)(&init_command),sizeof(init_command)) >= 10) {
        return 1;
    }

    return 0;
}

uint16_t read_bus_voltage(uint8_t addr, uint8_t chx,uint8_t *flag) {
	read[0] = 0;
	read[1] = 0;
	bvol = 0;
	if(vc_read_reg(addr,VC_BUSV_CHx(chx),read) == 0) {
		bvol = read[0]<<8 | read[1];
		*flag = 0;

	} else {
		*flag = 1;
		bvol = 0;
	}
	return bvol;
}

uint16_t read_shunt_voltage(uint8_t addr, uint8_t chx,uint8_t *flag) {
	read[0] = 0;
	read[1] = 0;
	bvol = 0;
	if(vc_read_reg(addr,VC_SHUNTV_CHx(chx),read) == 0) {
		bvol = read[0]<<8 | read[1];
		*flag = 0;
	} else {
		*flag = 1;
		bvol = 0;
	}
	return bvol;
}

uint16_t get_ADC_value(i2c_instance_t *i2c_chx,uint8_t address,uint8_t chx,uint8_t *flag) {
	uint8_t adc_read_value[2];
	uint8_t ch_read[] = {chx};
	ch_read[0] |= 0x8;
	ch_read[0] = ch_read[0] << 4;
	uint8_t status;
	uint16_t voltage;
	I2C_write_read(i2c_chx,address,ch_read,1,adc_read_value,2,I2C_RELEASE_BUS);
	status = I2C_wait_complete(i2c_chx, I2C_NO_TIMEOUT);
	if(status != 0) {
		*flag = 1;
	} else {
		voltage = (adc_read_value[0] << 8 ) | adc_read_value[1];
		voltage &= 0x0FFF;
		*flag = 0;
	}
	return voltage;
}

