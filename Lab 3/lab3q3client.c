/*				THE CLIENT PROCESS

	Please read the file server.c before you read this file. To run this,
	you must first change the IP address specified in the line:

		serv_addr.sin_addr.s_addr = inet_addr("144.16.202.221");

	to the IP-address of the machine where you are running the server.
*/

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
	int buf[5];
	int buff[5];
	struct sockaddr_in sa_addr;

	/* Opening a socket is exactly similar to the server process */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	/* Recall that we specified INADDR_ANY when we specified the server
	address in the server. Since the client can run on a different
	machine, we must specify the IP address of the server.

	TO RUN THIS CLIENT, YOU MUST CHANGE THE IP ADDRESS SPECIFIED
	BELOW TO THE IP ADDRESS OF THE MACHINE WHERE YOU ARE RUNNING
	THE SERVER.*/
	sa_addr.sin_family = AF_INET;
	sa_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //Loop back IP address
	sa_addr.sin_port = htons(6000);
	memset(sa_addr.sin_zero, '\0', sizeof sa_addr.sin_zero);

	/* With the information specified in serv_addr, the connect()
	system call establishes a connection with the server process.*/
	i = connect(sockfd, (struct sockaddr *)&sa_addr, sizeof(sa_addr));

	/* After connection, the client can send or receive messages.
	However, please note that recv() will block when the
	server is not sending and vice versa. Similarly send() will
	block when the server is not receiving and vice versa. For
	non-blocking modes, refer to the online man pages.*/
	printf("Enter 5 numbers: ");
	int ii;
	for(ii=0;ii<5;ii++)
	{
		scanf("%d", (buf+ii));
	}
	
	
	send(sockfd, buf, 20, 0);
	
	
	
	recv(sockfd, buff, 20, 0);
	
	printf("Sorted array: ");
	for(ii=0;ii<5;ii++)
	{
		printf("%d, ", buff[ii]);
	}
	printf("\n");

	close(sockfd);


}




























