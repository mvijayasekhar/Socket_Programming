#ifndef _MY_HEADER_
#define _MY_HEADER_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#define MAX_BUFFER 1024
#define PORT_NUM 8001
#define Q_LEN 10

typedef struct sockaddr SOCK_ADDR;
typedef struct sockaddr_in SOCK_ADDR_IN;
typedef struct sctp_initmsg SCTP_INIT_MSG;                                                  
typedef	struct sctp_sndrcvinfo SCTP_SNDRCVINFO;
#endif

