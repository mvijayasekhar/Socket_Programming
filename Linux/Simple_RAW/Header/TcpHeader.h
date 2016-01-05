#ifndef __TCP_HEADER__
#define __TCP_HEADER__

typedef struct tcp_header{                                                             
	unsigned short int src_port;                                            
	unsigned short int dest_port;                                           
	unsigned int seq_no;                                                    
	unsigned int ack_no;                                                    
	unsigned char res_bits:4;                                               
	unsigned char h_len:4;                                                  
	unsigned char fin:1;                                                    
	unsigned char syn:1;                                                    
	unsigned char rst:1;                                                    
	unsigned char psh:1;                                                    
	unsigned char ack:1;                                                    
	unsigned char urg:1;                                                    
	unsigned char ece:1;                                                    
	unsigned char cwr:1;                                                    
	unsigned short int win_size;                                            
	unsigned short int check_sum;                                           
	unsigned short int urg_ptr;                                             
} tcp_header_t, *tcp_header_p;

#endif
