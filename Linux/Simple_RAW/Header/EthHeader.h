#ifndef __ETH_HEADER__
#define __ETH_HEADER__
struct ethhdr{                                                              
	unsigned char d_mac[6];                                                 
	unsigned char s_mac[6];                                                 
	unsigned short int type;                                                
} *eth;
#endif
