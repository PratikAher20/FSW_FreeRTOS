#include "devices.h"



#ifndef _GET_DATA_H
#define _GET_DATA_H

#define IMU_ADDR 0x6a
#define VC1 0x40
#define VC_SENSOR_I2C &g_core_i2c3
#define DAC_ADDR 0x0E

#define VC_INIT_CMD                     0x7007
#define VC_CONFIG_REG 					0x00

#define VC_BUSV_CHx(x)                  ((0x2 * x))
#define VC_SHUNTV_CHx(x)                ((0x2 * x - 1))

#define COREI2C_2_0   0x50002000U
#define COREI2C_3_0   0x50003000U
#define COREI2C_4_0   0x50004000U
#define COREI2C_5_0   0x50005000U

// i2c_instance_t g_core_i2c5;

uint8_t get_IMU_acc(uint16_t *a_x,uint16_t *a_y,uint16_t *a_z);
uint8_t get_IMU_gyro(uint16_t *roll_rate, uint16_t *pitch_rate,uint16_t *yaw_rate);
uint8_t get_IMU_temp(uint16_t *temp);
uint16_t get_ADC_value(i2c_instance_t *i2c_chx,uint8_t address,uint8_t chx,uint8_t *flag);

uint8_t add(uint8_t a, uint8_t b);

#endif
