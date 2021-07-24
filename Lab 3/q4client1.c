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

	buf = 1905387;
	printf("Sending %d from client 1 to client 2\n", buf);
	send(sockfd, &buf, sizeof(int), 0);

	buf = 0;

	recv(sockfd, &buf, sizeof(int), 0);
	printf("Received %d in client 1\n", buf);


	close(sockfd);

}
