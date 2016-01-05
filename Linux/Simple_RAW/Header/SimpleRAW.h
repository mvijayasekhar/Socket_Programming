#ifndef _MY_HEADER_
#define _MY_HEADER_


#include    <stdio.h>
#include    <errno.h>
#include    <stdlib.h>
#include    <string.h>
#include    <unistd.h>
#include    <sys/types.h>
#include    <arpa/inet.h>
#include    <sys/socket.h>
#include    <netinet/ip.h>
#include 	<linux/if_ether.h>

#define		MAX_SIZE 65535

#include	"EthHeader.h"
#include	"IpHeader.h"
#include	"TcpHeader.h"
#include	"UdpHeader.h"

void print_eth_header(ethernet_header_p);
int print_ip_header(ip_header_p);
void print_tcp_header(tcp_header_p);
void print_udp_header(udp_header_p);

#endif

