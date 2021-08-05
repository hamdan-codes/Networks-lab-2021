/*
** A datagram "client" demo
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define SERVERPORT 4952 // the port users will be connecting to
int main()
{
	int sockfd;
	struct sockaddr_in their_addr; // connector's address information
//struct hostent *he;
	socklen_t addr_len;
	int numbytes;
	int arg;
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}
	their_addr.sin_family = AF_INET; // host byte order
	their_addr.sin_port = htons(SERVERPORT); // short, network byte order
	their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
//memset(their_addr.sin_zero, '\0', sizeof their_addr.sin_zero);
	printf("Enter a number to search in array: ");
	scanf("%d", &arg);
	if ((numbytes = sendto(sockfd, &arg, sizeof(int), 0,
	                       (struct sockaddr *)&their_addr, sizeof their_addr)) == -1) {
		perror("sendto");
		exit(1);
	}
	printf("sent %d bytes to %s\n", numbytes, inet_ntoa(their_addr.sin_addr));

	recvfrom(sockfd, &arg, 200 - 1 , 0,
	         (struct sockaddr *)&their_addr, &addr_len);

	printf("Element found at: %d\n", arg);


	close(sockfd);
	return 0;
}





























