#ifndef __ETH_HEADER__
#define __ETH_HEADER__
typedef struct ethernet_header{                                                              
	unsigned char d_mac[6];                                                 
	unsigned char s_mac[6];                                                 
	unsigned short int type;                                                
} ethernet_header_t, *ethernet_header_p;
#endif
