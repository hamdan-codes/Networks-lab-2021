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
#define SERVERPORT 4952


int main()
{
	int sockfd;
	struct sockaddr_in their_addr;
	
	socklen_t addr_len;
	int numbytes;
	char arg[30];
	
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(SERVERPORT);
	their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	printf("Enter a command: ");
	gets(arg);
	if ((numbytes = sendto(sockfd, arg, strlen(arg), 0,
	                       (struct sockaddr *)&their_addr, sizeof their_addr)) == -1) {
		perror("sendto");
		exit(1);
	}
	printf("sent %d bytes to %s\n", numbytes, inet_ntoa(their_addr.sin_addr));
	
	
	char rec[20][20];
	
	recvfrom(sockfd, rec, sizeof(rec) , 0,
	                         (struct sockaddr *)&their_addr, &addr_len);
	
	printf("Files present: \n");
	for(int i=0;i<10;i++) {
		printf("%s, ", rec[i]);
	}
	
	printf("\n");
	
	close(sockfd);
	
	return 0;
}





























