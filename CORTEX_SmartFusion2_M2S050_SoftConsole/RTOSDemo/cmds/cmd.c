
#include "cmd.h"

cmd_t* cmd;

// Function checking the CheckSUM
//void chk_sum();

cmd_t cmd_list[NUM_CMDS];

uint8_t cmd_valid(rx_cmd_t* rx_cmd){
	return 1;  //Will be checking the validated of the checksum.
}

uint8_t chk_s_cmd(rx_cmd_t* rx_cmd){
	uint16_t p;

	p = PILOT_REVERSE_BYTE_ORDER(rx_cmd->ccsds_cmd_p1);

	cmd->length = p & 0x07FF;

	if( (p >> 11) & 0x01){
		return 1;
	}
	else{
		return 0;
	}
}


void add_cmd(uint8_t id, uint16_t length, void (*ex_func)(uint8_t id, uint8_t opcode, uint16_t length)){

	cmd_list[id].id = id;
	cmd_list[id].length = length;
	cmd_list[id].ex_func = ex_func;

}

void vcmd_callback(){
	//Execution for the timer based command
}

void cmd_engine(rx_cmd_t* rx_cmd){

	add_cmd(1, 2, cmd_noop);

	if(chk_s_cmd(rx_cmd)){
		cmd_timer[0] = xTimerCreate("cmd_timer", pdMS_TO_TICKS(rx_cmd->ccsds_time), pdFALSE, (void*)0, vcmd_callback);
		xTimerStart(cmd_timer[0], 0);
	}
	else{
		 //Commands needs to be executed right now.
//		add_cmd(rx_cmd->ccsds_APID, cmd->length, cmd_list[rx_cmd->ccsds_APID].ex_func(rx_cmd->ccsds_APID, rx_cmd->parameters, cmd->length));
		cmd_list[rx_cmd->ccsds_APID].ex_func(rx_cmd->ccsds_APID, rx_cmd->parameters, cmd->length);
	}

}

// Commands Definition

void cmd_noop(uint8_t id, uint8_t opcode, uint16_t length){

	uint8_t a;

}

void set_pkt_rate(uint8_t id, uint8_t opcode, uint16_t length){

	pkt_rate_t* pkt_rate;
	pkt_rate = (pkt_rate_t* )opcode;

	// Write a function to take in APID and increase the downlink rate of that pkt.
	if(pkt_rate->pkt_apid == HK_API_ID){
//		xTimerChangePeriod() Change the downlink rate of HK packet
	}


}

