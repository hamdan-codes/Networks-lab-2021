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


struct student {
	int roll;
	char name[10];
	int marks[5];
};




int main()
{
	int sockfd;
	int buf;
	struct sockaddr_in their_addr;
	struct student rec;
	socklen_t addr_len;
	int numbytes;
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(SERVERPORT);
	their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	printf("Enter roll to search: ");
	scanf("%d", &buf);
	
	if ((numbytes = sendto(sockfd, &buf, sizeof(buf), 0,
	                       (struct sockaddr *)&their_addr, sizeof their_addr)) == -1) {
		perror("sendto");
		exit(1);
	}
	printf("sent %d bytes to %s\n", numbytes, inet_ntoa(their_addr.sin_addr));
	
	recvfrom(sockfd, &rec, sizeof(rec) , 0,
	                         (struct sockaddr *)&their_addr, &addr_len);
	
	printf("Received Data, roll = %d, name = %s\n", rec.roll, rec.name);
	printf("Marks = %d, %d, %d, %d, %d\n", rec.marks[0], rec.marks[1], rec.marks[2], rec.marks[3], rec.marks[4]);
	
	close(sockfd);
	return 0;
}
















