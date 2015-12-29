#ifndef __UDP_HEADER__
#define __UDP_HEADER__

struct udp_hdr {                                                            
	unsigned short int src_port;                                            
	unsigned short int dest_port;                                           
	unsigned short int total_len;                                           
	unsigned short int check_sum;                                           
} *udp_hdr;

#endif
