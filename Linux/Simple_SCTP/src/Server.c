/** @mainpage   Implementing SCTP Socket                                         
 *  @file   Server.c                                                            
 *  @brief  SCTP server program                                                  
 *  @author Vijaya Sekhar M                                                     
 *  @date   September 2015                                                         
 *  @version    1.0                                                             
 *  @bug    No known bugs.                                                      
 */  

#include	"SimpleSCTP.h"
 
int main(int argc, char *argv[])
{
  int listenSock, connSock, in , flags;
  SOCK_ADDR_IN servaddr;
  SCTP_INIT_MSG initmsg;
  SCTP_SNDRCVINFO sndrcvinfo;


  if (argc <= 1) {                                                            
	  fprintf(stderr,"usage: SERVER <ip-addr>\n");                            
	  exit(EXIT_FAILURE);                                                     
  } 
 
  /** initialising the structure variables*/ 
  bzero( (void *)&servaddr, sizeof(servaddr) );
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  servaddr.sin_port = htons(PORT_NUM);
	
  /** creating a new socket*/
  if ( -1 == (listenSock = socket( AF_INET, SOCK_STREAM, IPPROTO_SCTP ))) {
	  fprintf(stderr,"socket: %s\n",strerror(errno));                         
	  exit(EXIT_FAILURE);
  }

  /** assigning an local address to the newly created socket*/
  if ( -1 == bind( listenSock, (SOCK_ADDR *)&servaddr, sizeof(servaddr) )) {
	  fprintf(stderr,"bind:%s\n",strerror(errno));                            
	  exit(EXIT_FAILURE); 
  }

  /** Specify that a maximum of Q_LEN streams will be available per socket */
  memset( &initmsg, 0, sizeof(initmsg) );
  initmsg.sinit_num_ostreams = Q_LEN;
  initmsg.sinit_max_instreams = Q_LEN;
  initmsg.sinit_max_attempts = 4;

  /** set the socket options*/
  if ( -1 == setsockopt( listenSock, IPPROTO_SCTP, SCTP_INITMSG, 
			  &initmsg, sizeof(initmsg) )) {
	  fprintf(stderr,"setsockopt:%s\n",strerror(errno));                              
	  exit(EXIT_FAILURE);
  }

  /** listening to the requested connctions and maintaing the queue*/ 
  if ( -1 == listen( listenSock, Q_LEN )) {
	  fprintf(stderr,"listen:%s\n",strerror(errno));                          
	  exit(EXIT_FAILURE); 
  }

  while( 1 ) {
 
  char buffer[MAX_BUFFER + 1];
 
  bzero(buffer, MAX_BUFFER + 1);
 
  printf("Server Listening..\n");

  /** accepting the connction from the queue that was maintained          
   *  by the listen syscall and creates a new socket to make a
   *  connection with the requested client from queue */
  if ( -1 == (connSock = accept( listenSock, (SOCK_ADDR *)NULL, (int *)NULL ))) {
	  fprintf(stderr,"accept:%s\n",strerror(errno));                      
	  exit(EXIT_FAILURE);
  }
  printf("New client connected....\n");
  if ( -1 == sctp_recvmsg( connSock, buffer, sizeof(buffer),
				  (SOCK_ADDR *)NULL, 0, &sndrcvinfo, &flags )) {
	  fprintf(stderr,"sctp_recvmsg: %s\n",strerror(errno));                       
	  exit(EXIT_FAILURE);
  }
  printf(" Data : %s\n", (char*)buffer);
  close( connSock );
  }

  return 0;
}
