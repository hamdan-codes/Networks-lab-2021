/*
** A datagram sockets "server" demo
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
#define MYPORT 4952
#define MAXBUFLEN 200


struct student {
	int roll;
	char name[10];
	int marks[5];
};






int main()
{
	int sockfd;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	socklen_t addr_len;
	int rn;
	struct student buf;
	struct student arr[10];
	int a;
	for(a=0;a<10;a++) {
		arr[a].roll = a+1;
		strcpy(arr[a].name,"Name");
		int aa;
		for(aa=0;aa<5;aa++)
			arr[a].marks[aa] = (a*10)+aa;
	}
	
	int numbytes;
	
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(MYPORT);
	my_addr.sin_addr.s_addr = INADDR_ANY; 
	
	if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1) {
		perror("bind");
		exit(1);
	}
	addr_len = sizeof their_addr;
	if ((numbytes = recvfrom(sockfd, &rn, sizeof(rn), 0,
	                         (struct sockaddr *)&their_addr, &addr_len)) == -1) {
		perror("recvfrom");
		exit(1);
	}
	printf("got packet from %s\n", inet_ntoa(their_addr.sin_addr));
	printf("packet is %d bytes long\n", numbytes);
	
	printf("packet contains \"%d\"\n", rn);
	
	int flag = 1;
	for(a=0;a<10;a++) {
		if(arr[a].roll == rn) {
			buf = arr[a];
			flag = 0;
			break;
		}
	}
	
	if(flag) {
		buf.roll = -1;
		strcpy(buf.name, "Not Found");
		int aa;
		for(aa=0;aa<5;aa++)
			buf.marks[aa] = -1;
	}
	
	
	
	
	
	sendto(sockfd, &buf, sizeof(buf), 0, (struct sockaddr *)&their_addr, sizeof their_addr);
	
	close(sockfd);
	return 0;
}













