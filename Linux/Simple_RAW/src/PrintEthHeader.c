#include    "SimpleRAW.h"

void print_eth_header(ethernet_header_p eth_hdr)
{
	int loop;
	printf("**********Ethernet Header***********\n");                       
	printf("\nDestination MAC Address:");                                    
	for(loop = 0; loop < 6 ; loop++)                                                 
		printf("%x:",eth_hdr->d_mac[loop]);                                    
	printf("\nSource MAC Address:");                                         
	for(loop = 0; loop < 6 ; loop++)                                                 
		printf("%x:",eth_hdr->s_mac[loop]);                                    
	printf("\nType :");                                                     
	printf("0x%x\n",ntohs(eth_hdr->type));                               
}
