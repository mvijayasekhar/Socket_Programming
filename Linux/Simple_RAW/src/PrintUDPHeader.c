#include    "SimpleRAW.h"

void print_udp_header(udp_header_p udp_hdr)
{
	printf("************UDP HEADER************\n");                     
	printf("Source Port : %d\n",udp_hdr->src_port);                     
	printf("Destination Port : %d\n",udp_hdr->dest_port);                      
	printf("Total Length : %d\n",udp_hdr->total_len);                   
	printf("Check Sum : %d\n",udp_hdr->check_sum);

}
