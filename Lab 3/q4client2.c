#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
main()
{
	int i, sockfd;
	int buf;
	struct sockaddr_in sa_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	sa_addr.sin_family = AF_INET;
	sa_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sa_addr.sin_port = htons(6000);
	memset(sa_addr.sin_zero, '\0', sizeof sa_addr.sin_zero);

	i = connect(sockfd, (struct sockaddr *)&sa_addr, sizeof(sa_addr));


	recv(sockfd, &buf, sizeof(int), 0);
	printf("Received %d in client 2 and sending the same to server.\n", buf);
	send(sockfd, &buf, sizeof(int), 0);


	close(sockfd);


}
