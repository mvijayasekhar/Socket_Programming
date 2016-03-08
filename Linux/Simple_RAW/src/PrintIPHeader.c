#include    "SimpleRAW.h"

int print_ip_header(ip_header_p ip_hdr)
{
	int loop;
	unsigned char *ptr;
	printf("**************IP Header**************\n");                      
	printf("Version : %d\n",ip_hdr->ver);                                   
	printf("Length : %d\n",ip_hdr->hlen);                                      
	printf("Type of Service : %d\n",ip_hdr->tos);                                       
	printf("Total Length : %d\n", htons (ip_hdr->t_len));                   
	printf("Identification : 0x%x\n",ip_hdr->ident);                        
	printf("Flags : %d\n",ip_hdr->flag);                                    
	printf("Offset : %d\n",ip_hdr->frag);                                   
	printf("TTL : %d\n",ip_hdr->ttl);                                       
	printf("Protocol : 0x%x\n",ip_hdr->protocol);                           
	printf("Check Sum :0x%x\n",ip_hdr->check_sum);                          

	printf("Source Address: ");
	ptr = (unsigned char *)&(ip_hdr->s_addr);                               
	for(loop = 0; loop < 4; loop++)                                                  
		printf("%u.",*(ptr + loop));                                           
	printf("\n");                                                           

	printf("Destination Address: ");
	ptr = (unsigned char *)&(ip_hdr->d_addr);                               
	for(loop = 0; loop < 4; loop++)                                                  
		printf("%u.",*(ptr + loop));                                           
	printf("\n");               

	return ip_hdr->protocol;
}
