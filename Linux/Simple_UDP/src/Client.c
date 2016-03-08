#include    "SimpleUDP.h"

int main(int argc,char *argv[])
{
	int sock_fd;
	long addr;
	unsigned int len;
	typedef struct sockaddr SOCK_ADDR;
	typedef struct sockaddr_in SOCK_ADDR_IN;
	SOCK_ADDR_IN ser_var;

	char *buf , *str;

	if (argc <= 1) {
		fprintf(stderr,"usage<a.out><ip_addr>\n");
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

	/** creating a socket*/
	if (-1 == (sock_fd = socket(AF_INET,SOCK_DGRAM,17))) {
		fprintf(stderr,"socket: %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}


	len = sizeof(ser_var);

	printf("\nEnter the Message: ");
	fgets(buf,MAX,stdin);

	/** sending msg to created socket*/
	if(-1 == sendto(sock_fd,buf,MAX,0,(SOCK_ADDR*)&ser_var,len)) {
		fprintf(stderr,"sendto: %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	/** receving from the socket*/
	if(-1 == recvfrom(sock_fd,str,MAX,0,(SOCK_ADDR*)&ser_var,&len)) {
		fprintf(stderr,"recvfrom: %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("Message From\n%s\n",str);
	free(str);
	free(buf);

	return 0;
}


