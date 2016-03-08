#ifndef __UDP_HEADER__
#define __UDP_HEADER__

typedef struct udp_header {                                                            
	unsigned short int src_port;                                            
	unsigned short int dest_port;                                           
	unsigned short int total_len;                                           
	unsigned short int check_sum;                                           
} udp_header_t, *udp_header_p;

#endif
