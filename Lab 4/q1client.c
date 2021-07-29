#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>

struct student {
	int roll;
	char name[10];
	int marks[5];
}


main()
{
	int i, sockfd;
	int buf;
	struct student rec;
	struct sockaddr_in sa_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	
	sa_addr.sin_family = AF_INET;
	sa_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sa_addr.sin_port = htons(6000);
	memset(sa_addr.sin_zero, '\0', sizeof sa_addr.sin_zero);

	i = connect(sockfd, (struct sockaddr *)&sa_addr, sizeof(sa_addr));
	
	printf("Enter roll to search: ");
	scanf("%d", &buf);
	
	send(sockfd, &buf, sizeof(int), 0);
	
	recv(sockfd, &rec, sizeof(struct student), 0);
	
	printf("Received Data, roll = %d, name = %s\n", rec.roll, rec.name);
	printf("Marks = %d, %d, %d, %d, %d\n", rec.marks[0], rec.marks[1], rec.marks[2], rec.marks[3], rec.marks[4]);


	close(sockfd);


}





























