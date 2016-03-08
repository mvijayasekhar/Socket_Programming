#include	"SimpleRAW.h"


int main()
{
	char buff[MAX_SIZE];
	int sock_fd;
	int protocol;
	if ((sock_fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) == -1) {
		perror("socket()");
		exit(-1);
	}
	while(1) {
		if(recvfrom(sock_fd, buff, MAX_SIZE, 0, NULL, NULL) == -1) {
			perror("recvfrom()");
			exit(-1);
		}
		print_eth_header((ethernet_header_p)buff);
		protocol = print_ip_header((ip_header_p)(buff + sizeof(ethernet_header_t)));
		if (protocol == 0x6) {
			print_tcp_header((tcp_header_p)(buff + sizeof(ethernet_header_t) + sizeof(ip_header_t))); 
		} else if(protocol == 0x11) {
			print_udp_header((udp_header_p)(buff + sizeof(ethernet_header_t) + sizeof(ip_header_t))); 
		}
	}
	return 0;
}
