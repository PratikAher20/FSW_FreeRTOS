
#include "Demo_Tasks/demo_tasks.h"
#include "timers.h"

#ifndef __cmd_
#define __cmd_

#define MAX_CMD_PARAM 2
#define NUM_TIMER 1
#define NUM_CMDS 2
#define PILOT_REVERSE_BYTE_ORDER(var)	(((var) << 8) | ((var) >> 8))

TimerHandle_t cmd_timer[NUM_TIMER];

void cmd_noop(uint8_t id, uint8_t opcode, uint16_t length);
void set_pkt_rate(uint8_t id, uint8_t opcode, uint16_t length);

typedef struct cmd{

	uint8_t id;
	uint16_t length;
	void (*ex_func)(uint8_t id, uint8_t opcode, uint16_t length);

}__attribute__((packed))cmd_t;


typedef struct rx_cmd{

	uint16_t ccsds_cmd_p1;
	uint16_t ccsds_APID;
	uint8_t ccsds_time;
	uint8_t ccsds_chk_sum;

	uint8_t parameters[MAX_CMD_PARAM];

}__attribute__((packed))rx_cmd_t;


uint8_t cmd_valid(rx_cmd_t* rx_cmd);
void cmd_engine(rx_cmd_t* rx_cmd);

typedef struct pkt_rate{

	uint8_t pkt_apid;
	uint8_t pkt_rate;

}__attribute__((packed))pkt_rate_t;


#endif