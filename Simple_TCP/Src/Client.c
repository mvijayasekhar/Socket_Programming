#include	"SimpleTCP.h"

int main(int argc ,char *argv[])
{
	int sock_fd;
	SOCK_ADDR_IN cli_var;
	long addr;
	unsigned int len;
	char *buf = NULL;

	if (argc <= 1) {
		fprintf(stderr,"usage: <a.out> <ip-addr>\n");
		exit(EXIT_FAILURE);
	}

	if (!(buf = malloc(MAX))) {
		fprintf(stderr,"buf: Memory Allocation Failed\n");
		exit(EXIT_FAILURE);
	}

	addr = inet_addr(argv[1]);

	/** initializing the structure variables*/
	cli_var.sin_family = AF_INET;
	cli_var.sin_port = htons(PORT);
	cli_var.sin_addr.s_addr = addr;

	/** creating a new socket*/
	if (-1 == (sock_fd = socket(AF_INET,SOCK_STREAM,0))) {
			fprintf(stderr,"socket: %s\n",strerror(errno));
			exit(EXIT_FAILURE);
		}

	len = sizeof(SOCK_ADDR);

	/** establishing the connetion with the server*/
	if(-1 == connect(sock_fd,(SOCK_ADDR *)&cli_var,len)) {
		fprintf(stderr,"connect: %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("\nEnter the Message: ");
	fgets(buf,MAX,stdin);

	/** sending the message with respect to the sock_fd*/
	if(-1 == send(sock_fd,buf,MAX,0)) {
		fprintf(stderr,"%s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	bzero(buf,MAX);
	/** receiving the message from server*/
	if(-1 == recv(sock_fd,buf,MAX,0)) {
		fprintf(stderr,"%s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("Message Read: %s\n",buf);

	free(buf);
	close(sock_fd);

	return 0;
}


