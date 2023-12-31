///**
// * @file    :   packet_definitions.h
// * @author  :   Srinidhi G, Pratik Aher
// * @brief   :   This file contains the definitions of all the packet types used
// * @version :   1.0
// * @date    :   2023-01-24
// *
// * @copyright Copyright (c) 2023
// *
// */
//
//#ifndef _PACKET_DEFINITIONS_
//#define _PACKET_DEFINITIONS_
//
//#define THERMISTOR_API_ID			20
//#define THERMISTOR_PKT_LENGTH		sizeof(thermistor_pkt_t)
//#define THERMISTOR_FLETCHER_CODE	0xCDCD
//
//#define ARIS_API_ID           50
//#define ARIS_PKT_LENGTH       sizeof(aris_pkt_t)
//#define ARIS_FLETCHER_CODE    0xCDCD
//
//#define LOGS_API_ID			30
//#define LOGS_PKT_LENGTH		sizeof(log_packet_t)
//#define LOGS_FLETCHER_CODE	0xCDCD
//
//#define HK_API_ID			10
//#define HK_PKT_LENGTH		sizeof(hk_pkt_t)
//#define HK_FLETCHER_CODE	0xCDCD
//
//#define SD_HK_API_ID    	40
//#define SD_HK_PKT_LENGTH  sizeof(sd_hk_t)
//#define SD_HK_FLETCHER_CODE 0xCDCD
//
//#define TIME_API_ID			60
//#define TIME_PKT_LENGTH		sizeof(timer_pkt_t)
//#define TIME_FLETCHER_CODE	0xCDCD
//
//#define INIT_API_ID			70
//#define INIT_PKT_LENGTH		sizeof(init_pkt_t)
//
//typedef struct {
//    //CCSDS
//
//	uint16_t ccsds_p1;
//	uint16_t ccsds_p2;
//	uint16_t ccsds_p3;
//
//    uint32_t ccsds_s1;
//    uint32_t ccsds_s2;
//
//    uint32_t data_valid;
//    uint16_t thermistor_set_A[8];
//    uint16_t thermistor_set_B[8];
//    uint16_t thermistor_set_C[8];
//
//    uint16_t Fletcher_Code;
//}__attribute__((packed)) thermistor_pkt_t;
//
//typedef struct {
//	uint32_t collect_time;
//	uint8_t data_valid;
//	uint16_t aris_data[3];
//}__attribute__((packed)) aris_sample_t;
//
//typedef struct{
//    uint16_t ccsds_p1;
//    uint16_t ccsds_p2;
//    uint16_t ccsds_p3;
//
//    uint32_t ccsds_s1;
//    uint32_t ccsds_s2;
//
//    uint16_t aris_reset_count;
//    uint32_t start_time;
//
//    aris_sample_t aris_samples[20];
//
//    uint16_t Fletcher_Code;
//
//}__attribute__((packed)) aris_pkt_t;
//
//typedef struct {
//    //CCSDS
//
//    uint16_t ccsds_p1;
//    uint16_t ccsds_p2;
//    uint16_t ccsds_p3;
//
//    uint32_t ccsds_s1;
//    uint32_t ccsds_s2;
//
//    uint16_t q_head;
//    uint16_t q_tail;
//    uint8_t CDH_Periph_Status; //For all the 8 flags
//    uint16_t imu_temp;
//    uint16_t Acc[3];  // X,Y,Z Axis
//    uint16_t Angular_Rate[3]; //Pitch, Roll, Yaw
//    uint16_t Sensor_Board_VC[2];
//    uint16_t CDH_VC[2];
//    uint16_t Comms_VC[2];
//
//    uint32_t HK_Read_Pointer;
//    uint32_t HK_Write_Pointer;
//    uint32_t Thermistor_Read_Pointer;
//    uint32_t Thermistor_Write_Pointer;
//    uint32_t Logs_Read_Pointer;
//    uint32_t Logs_Write_Pointer;
//    uint32_t SD_Test_Read_Pointer;
//    uint32_t SD_Test_Write_Pointer;
//    uint32_t ARIS_Read_Pointer;
//    uint32_t ARIS_Write_Pointer;
//
//    uint16_t aris_miss;
//    uint16_t hk_miss;
//    uint16_t payload_miss;
//    uint16_t logs_miss;
//    uint16_t sd_hk_miss;
//    uint8_t sd_dump;
//    uint8_t sd_fail_count;
//    uint16_t aris_sample_miss;
//    uint8_t sensor_board_status;
//    uint8_t sensor_board_fail_count;
//    uint32_t sd_prev_wait_time;
//    uint16_t Fletcher_Code;
//}__attribute__((packed)) hk_pkt_t;
//
///**
// * @brief Each log entry has the below four fields for every task that occurs
// *
// */
//typedef struct {
//	uint32_t time_L;//lower time value
//	uint32_t time_H;//upper time value
//	uint8_t task_id;//task id
//	uint8_t task_status;//task status;
//}__attribute__((packed)) log_entry_t;
//
//typedef struct {
//    //CCSDS
//
//    uint16_t ccsds_p1;
//    uint16_t ccsds_p2;
//    uint16_t ccsds_p3;
//
//    uint32_t ccsds_s1;
//    uint32_t ccsds_s2;
//
//    log_entry_t logs[10];
//
//    uint16_t Fletcher_Code;
//}__attribute__((packed)) log_packet_t;
//
//typedef struct {
//    //CCSDS
//
//    uint16_t ccsds_p1;
//    uint16_t ccsds_p2;
//    uint16_t ccsds_p3;
//
//    uint32_t ccsds_s1;
//    uint32_t ccsds_s2;
//
////    uint16_t SD_Test_count[5];
////    uint16_t SD_Test_time[5];
//    uint32_t addr;
//    uint8_t sd_result;
//    uint16_t time;
//
//    uint16_t Fletcher_Code;
//}__attribute__((packed)) sd_test_t;
//
//typedef struct {
////	uint32_t sync;
//    uint16_t ccsds_p1;
//    uint16_t ccsds_p2;
//    uint16_t ccsds_p3;
//
//    uint32_t ccsds_s1;
//    uint32_t ccsds_s2;
//    uint8_t reset;
//    uint32_t reset_count;
//    uint8_t wd_reset;
//    uint16_t q_head;
//    uint16_t q_tail;
//	uint32_t lower_count;
//	uint32_t upper_count;
//    uint8_t adc_A;
//    uint8_t adc_B;
//    uint8_t adc_C;
//    uint8_t adc_D;
//    uint8_t vc_init;
//	uint16_t fletcher_code;
//}__attribute__((packed)) timer_pkt_t;
//
//typedef struct {
//	uint8_t task_id;
//	uint8_t sd_state;
//	uint16_t miss_margin;
//}__attribute__((packed)) sd_sample_t;
//
//typedef struct {
//    uint16_t ccsds_p1;
//    uint16_t ccsds_p2;
//    uint16_t ccsds_p3;
//
//    uint32_t ccsds_s1;
//    uint32_t ccsds_s2;
//    sd_sample_t samples[20];
//    uint16_t Fletcher_code;
//}__attribute__((packed)) sd_hk_t;
//
//typedef struct {
//	uint32_t reset_count;
//    uint32_t HK_Read_Pointer;
//    uint32_t HK_Write_Pointer;
//    uint32_t Thermistor_Read_Pointer;
//    uint32_t Thermistor_Write_Pointer;
//    uint32_t Logs_Read_Pointer;
//    uint32_t Logs_Write_Pointer;
//    uint32_t SD_Test_Read_Pointer;
//    uint32_t SD_Test_Write_Pointer;
//    uint32_t ARIS_Read_Pointer;
//    uint32_t ARIS_Write_Pointer;
//
//}__attribute__((packed)) reset_pkt_t ;
//
//#endif
