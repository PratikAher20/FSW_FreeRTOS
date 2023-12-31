
#include "cmd.h"

cmd_t* cmd;

// Function checking the CheckSUM
//void chk_sum();

cmd_t cmd_list[NUM_CMDS];

extern uint16_t command_cnt;
extern uint16_t command_reject_cnt;

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


void add_cmd(uint8_t id, uint16_t length, void (*ex_func)(uint8_t id, rx_cmd_t* rcv_cmd)){

	cmd_list[id].id = id;
	cmd_list[id].length = length;
	cmd_list[id].ex_func = ex_func;

}

void vcmd_callback(){
	//Execution for the timer based command
	cmd_list[rx_cmd->ccsds_APID - 1].ex_func(rx_cmd);
}

void cmd_engine(rx_cmd_t* rx_cmd){

	add_cmd(0, 16, cmd_noop);
	add_cmd(1, 16, set_pkt_rate);   //the actual command apid's is one greater than this.
	add_cmd(2, 16, cmd_sc_reset);

	if(chk_s_cmd(rx_cmd)){  //if the command is storable
		cmd_timer[0] = xTimerCreate("cmd_timer", pdMS_TO_TICKS(rx_cmd->ccsds_time * 1000), pdFALSE, (void*)0, vcmd_callback);
		xTimerStart(cmd_timer[0], 0);
	}
	else{
		 //Commands needs to be executed right now.
//		add_cmd(rx_cmd->ccsds_APID, cmd->length, cmd_list[rx_cmd->ccsds_APID].ex_func(rx_cmd->ccsds_APID, rx_cmd->parameters, cmd->length));
		cmd_list[rx_cmd->ccsds_APID - 1].ex_func(rx_cmd);
	}

}

// Commands Definition

void cmd_noop(rx_cmd_t* rcv_cmd){

	uint8_t a;

}

void set_pkt_rate(rx_cmd_t* rcv_cmd){

	if(rcv_cmd->parameters[1] != 0){
		xTimerChangePeriod(pkt_timer[rcv_cmd->parameters[0]], xMsToTicks(rcv_cmd->parameters[1] * 1000), 0);
	}
	else{
		xTimerStop(pkt_timer[rcv_cmd->parameters[0]], 0);
	}
	// Write a function to take in APID and increase the downlink rate of that pkt.
//	if(pkt_rate->pkt_apid == HK_API_ID){
//		xTimerChangePeriod() Change the downlink rate of HK packet
//	}

}

void cmd_sc_reset(rx_cmd_t* rcv_cmd){

	command_cnt = 0;
	// Power Cycle other Components;

}

