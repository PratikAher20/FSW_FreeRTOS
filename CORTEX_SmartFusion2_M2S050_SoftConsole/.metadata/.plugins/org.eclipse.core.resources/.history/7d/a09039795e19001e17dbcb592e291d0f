
#include "stream.h"
#include "Demo_Tasks/demo_tasks.h"


void set_pktRate(pkt_name_t pn, uint8_t sr){

	pkt_stream[pn].rate = sr * 1000;

}

void pkt_send(stream_t ps){

	MSS_UART_polled_tx(&g_mss_uart0, ps.pkt.pkt_data, ps.pkt.pkt_size);

}
