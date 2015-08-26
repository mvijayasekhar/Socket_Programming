#include	"SimpleTCP.h"

int main(int argc ,char *argv[])
{
	int sock_fd, new_fd;
	SOCK_ADDR_IN ser_var,cli_var;
	long addr;
	unsigned int len;
	char *buf = NULL;
	char *var = "From Global Edge";

	if (argc <= 1) {
		fprintf(stderr,"usage: <a.out><ip-addr>\n");
		exit(EXIT_FAILURE);
	}

	if (!(buf = malloc(MAX))) {
		fprintf(stderr,"buf: Memory Allocation Failed\n");
		exit(EXIT_FAILURE);
	}

	addr = inet_addr(argv[1]);

	/** initialising the structure variables*/
	ser_var.sin_family = AF_INET;
	ser_var.sin_port = htons(PORT);
	ser_var.sin_addr.s_addr = addr;

	/** creating a new socket*/
	if (-1 == (sock_fd = socket(AF_INET,SOCK_STREAM,0))) {
		fprintf(stderr,"socket: %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	/** assigning an local address to the newly created socket*/
	if(-1 == bind(sock_fd,(SOCK_ADDR*)&ser_var,sizeof(SOCK_ADDR))) {
		fprintf(stderr,"bind:%s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	/** listening to the requested connctions and maintaing the queue*/
	if(-1 == listen(sock_fd,Q_LEN)) {
		fprintf(stderr,"listen:%s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}

	len = sizeof(SOCK_ADDR);

	while (1) {
		/** accepting the connction from the queue that was maintained
		 * by the listen syscall and creates a new socket to make a connection
		 * with the requested client from queue */
		if(-1 == (new_fd = accept(sock_fd,(SOCK_ADDR *)&cli_var, &len))) {
			fprintf(stderr,"accept:%s\n",strerror(errno));
			exit(EXIT_FAILURE);
		}

		if(-1 == recv(new_fd,buf,MAX,0)) {
			fprintf(stderr,"recv: %s\n",strerror(errno));
			exit(EXIT_FAILURE);
		}
		printf("Message Read: %s",buf);
		if(-1 == send(new_fd,var,MAX,0)) {
			fprintf(stderr,"send:%s\n",strerror(errno));
			exit(EXIT_FAILURE);
		}
		bzero(buf,MAX);
	}
	free(buf);
	close(new_fd);
	close(sock_fd);

}

