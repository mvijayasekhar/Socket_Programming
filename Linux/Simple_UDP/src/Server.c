#include    "SimpleUDP.h"

int main(int argc,char *argv[])
{
	int sock_fd ;
	long addr;
	unsigned int len;
	typedef struct sockaddr SOCK_ADDR;
	typedef struct sockaddr_in SOCK_ADDR_IN;
	SOCK_ADDR_IN ser_var,cli_var;
	char *buf , *str;

	if(argc <= 1) {
		fprintf(stderr,"Usage:SERVER <ip-addr>\n");
		exit(EXIT_FAILURE);
	}

	if(!(buf = malloc(MAX))) {
		fprintf(stderr,"Memory Allocation Failed\n");
		exit(EXIT_FAILURE);
	}

	if(!(str = malloc(MAX))) {
		fprintf(stderr,"Memory Allocation Failed\n");
		exit(EXIT_FAILURE);
	}
		addr = inet_addr(argv[1]);

		ser_var.sin_family = AF_INET;
		ser_var.sin_port = htons(port);
		ser_var.sin_addr.s_addr = addr;

		/** creating a socket */

		if (-1 == (sock_fd = socket(AF_INET,SOCK_DGRAM,17))) {
			fprintf(stderr,"socket: %s\n",strerror(errno));
			exit(EXIT_FAILURE);
		}

		/** generating the address for the socket*/

		if (-1 == bind(sock_fd, (SOCK_ADDR *)&ser_var, sizeof(SOCK_ADDR))) {
			fprintf(stderr,"bind: %s\n",strerror(errno));
			exit(EXIT_FAILURE);
		}

		len = sizeof(cli_var);

		/** getting the hostname*/

		if(-1 == gethostname(str,MAX)) {
			fprintf(stderr,"gethostname: %s\n",strerror(errno));
			exit(EXIT_FAILURE);
		}

		sprintf(buf,"Server Name: %s, IP Address: %s",str,argv[1]);

		bzero(str,MAX);
		while (1) {
			/** receving the msg from the client */
			if(-1 == recvfrom(sock_fd,str,MAX,0,(SOCK_ADDR *)&cli_var,&len)) {
				fprintf(stderr,"recvfrom: %s\n",strerror(errno));
				exit(EXIT_FAILURE);
			}
			printf("Message: %s",str);
			/** sending the msg client */
			if(-1 == sendto(sock_fd,buf,MAX,0,(SOCK_ADDR*)&cli_var,len)) {
				fprintf(stderr,"sendto: %s\n",strerror(errno));
				exit(EXIT_FAILURE);
			}
		}

		free(str);
		free(buf);
		close(sock_fd);
		return 0;
	}

