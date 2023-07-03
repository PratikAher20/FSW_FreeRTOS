
#include "Demo_Tasks/demo_tasks.h"

#ifndef __STREAM__H
#define __STREAM__H



typedef struct stream{

	pkt_t pkt;

	uint16_t* pkt_timer_id;
//	uint8_t pkt_priority;  How to use the Priority within the queue

	uint16_t rate;

}__attribute__((packed))stream_t;

stream_t pkt_stream[NUM_PKTS];

void set_pktRate(pkt_name_t , uint8_t );
void pkt_send(stream_t ps);
//extern uint16_t command_cnt = 0;
//extern uint16_t command_reject_cnt = 0;









#endif
