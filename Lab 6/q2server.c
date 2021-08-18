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
#include <dirent.h>
#define MYPORT 4952
#define MAXBUFLEN 200



int main()
{
	int sockfd;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	socklen_t addr_len;
	char com[30];
	char rec[20][20];
	
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
	if ((numbytes = recvfrom(sockfd, com, sizeof(com), 0,
	                         (struct sockaddr *)&their_addr, &addr_len)) == -1) {
		perror("recvfrom");
		exit(1);
	}
	printf("got packet from %s\n", inet_ntoa(their_addr.sin_addr));
	printf("packet is %d bytes long\n", numbytes);
	
	printf("packet contains \"%s\"\n", com);
	
	if(strcmp(com, "list")) {
		DIR *d;
		struct dirent *dir;
		d = opendir(".");
		if (d)
		{
			int i=-1;
			while ((dir = readdir(d)) != NULL)
			{
				i++;
				printf("%s, ", dir->d_name);
				strcpy(rec[i], dir->d_name);
			}
			closedir(d);
		}
	}
	
	
	
	
	
	sendto(sockfd, rec, sizeof(rec), 0, (struct sockaddr *)&their_addr, sizeof their_addr);
	
	close(sockfd);
	return 0;
}













