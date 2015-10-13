/** @mainpage   Implementing TCP Socket 
 *  @file		SimpleTCP.h
 *  @brief		Include all headers and macros
 *  @author		Vijaya Sekhar M
 *  @date		August 2015
 *  @version	1.0
 *  @bug		No known bugs.
 */ 

#ifndef _MY_HEADER_
#define _MY_HEADER_


#include    <stdio.h>
#include    <stdlib.h>
#include    <sys/types.h>
#include    <sys/socket.h>
#include    <string.h>
#include    <errno.h>
#include    <netinet/ip.h>
#include    <arpa/inet.h>
#include    <unistd.h>


#define PORT 8001
#define MAX 100
#define Q_LEN 10

typedef struct sockaddr SOCK_ADDR;
typedef struct sockaddr_in SOCK_ADDR_IN;

#endif

