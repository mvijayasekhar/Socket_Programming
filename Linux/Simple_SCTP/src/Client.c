/** @mainpage   Implementing SCTP Socket                                         
 *  @file   Client.c                                                            
 *  @brief  SCTP client program                                                  
 *  @author Vijaya Sekhar M                                                     
 *  @date   September 2015                                                         
 *  @version    1.0                                                             
 *  @bug    No known bugs.                                                      
 */                                                                             
                                                                                
#include    "SimpleSCTP.h"
 
int main(int argc, char *argv[])
{
  int connSock;
  SOCK_ADDR_IN servaddr;
  char buffer[MAX_BUFFER+1];

  if (argc <= 1) {                                                            
	  fprintf(stderr,"usage: CLIENT <ip-addr>\n");                           
	  exit(EXIT_FAILURE);                                                     
  }   
  /* Sample input*/
  strncpy(buffer, "Hello Server", 12);
  buffer[12]='\0';
  
  /** initializing the structure variables*/ 
  bzero( (void *)&servaddr, sizeof(servaddr) );
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT_NUM);
  servaddr.sin_addr.s_addr = inet_addr( argv[1] );

  /** creating a new socket*/ 
  if ( -1 == (connSock = socket( AF_INET, SOCK_STREAM, IPPROTO_SCTP ))) {
	  fprintf(stderr,"socket: %s\n",strerror(errno));                     
	  exit(EXIT_FAILURE);
  }

  /** establishing the connetion with the server*/
  if ( -1 == connect( connSock, (SOCK_ADDR *)&servaddr, sizeof(servaddr) )) {
	  fprintf(stderr,"connect: %s\n",strerror(errno));                        
	  exit(EXIT_FAILURE);
  }

  /** sending the message with respect to the connSock*/
  if ( -1 == sctp_sendmsg( connSock, (void *)buffer, (size_t)strlen(buffer),
			  NULL, 0, 0, 0, 0, 0, 0 )) {
	  fprintf(stderr,"sctp_sendmsg %s\n",strerror(errno));                                 
	  exit(EXIT_FAILURE); 
  }
  close(connSock);
 
  return 0;
}
