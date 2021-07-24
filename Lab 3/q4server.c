#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
main()
{
	int sockfd, fd1, fd2, length, i;
	int buf;
	struct sockaddr_in sa_addr, cl_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	sa_addr.sin_family = AF_INET;
	sa_addr.sin_addr.s_addr = INADDR_ANY;
	sa_addr.sin_port = htons(6000);
	memset(sa_addr.sin_zero, '\0', sizeof sa_addr.sin_zero);

	i = bind(sockfd, (struct sockaddr *)&sa_addr, sizeof(sa_addr));
	printf("test %d%d\n", sockfd, i);

	listen(sockfd, 5);

	length = sizeof(cl_addr);
	fd1 = accept(sockfd, (struct sockaddr *) &cl_addr, &length);
	fd2 = accept(sockfd, (struct sockaddr *) &cl_addr, &length);

	recv(fd1, &buf, sizeof(int), 0);
	send(fd2, &buf, sizeof(int), 0);

	recv(fd2, &buf, sizeof(int), 0);
	printf("Received %d in server and sending the same to client 1.\n", buf);
	send(fd1, &buf, sizeof(int), 0);

	close(fd1);

}
