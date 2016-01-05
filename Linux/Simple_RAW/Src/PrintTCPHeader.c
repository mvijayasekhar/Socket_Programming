#include    "SimpleRAW.h"

void print_tcp_header(tcp_header_p tcp_hdr)
{

	printf("***********TCP HEADER**********\n");                        
	printf("Source Port Address : 0x%x\n",htons(tcp_hdr->src_port));    
	printf("Destination Port Address : 0x%x\n",htons(tcp_hdr->dest_port));
	printf("Sequence Number : %d\n",tcp_hdr->seq_no);                   
	printf("Acknowledge Number : %d\n",tcp_hdr->ack_no);                
	printf("Reserved Bits : %d\n",tcp_hdr->res_bits);                   
	printf("***********Flags****************\n");                       
	printf("FIN : %d\n",tcp_hdr->fin);                                  
	printf("SYN : %d\n",tcp_hdr->syn);                                  
	printf("RST : %d\n",tcp_hdr->rst);                                  
	printf("PSH : %d\n",tcp_hdr->psh);                                  
	printf("ACK : %d\n",tcp_hdr->ack);                                  
	printf("URG : %d\n",tcp_hdr->urg);                                  
	printf("ECE : %d\n",tcp_hdr->ece);                                  
	printf("CWR : %d\n",tcp_hdr->cwr);                                  
	printf("*********************************\n");                      
	printf("Window Size : %d\n",tcp_hdr->win_size);                                   
	printf("Check Sum : %d\n",tcp_hdr->check_sum);                                  
	printf("Urgent Pointer : %d\n",tcp_hdr->urg_ptr); 

}
