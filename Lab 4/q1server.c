
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
};


int main()
{
	int sockfd, fd1, fd2, length, i;
	int rn;
	struct student buf;
	struct sockaddr_in sa_addr, cl_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	sa_addr.sin_family = AF_INET;
	sa_addr.sin_addr.s_addr = INADDR_ANY;
	sa_addr.sin_port = htons(6000);
	memset(sa_addr.sin_zero, '\0', sizeof sa_addr.sin_zero);

	i = bind(sockfd, (struct sockaddr *)&sa_addr, sizeof(sa_addr));
	printf("test %d%d\n", sockfd, i);

	listen(sockfd, 5);
	
	struct student arr[10];
	int a;
	for(a=0;a<10;a++) {
		arr[a].roll = a+1;
		strcpy(arr[a].name,"Name");
		int aa;
		for(aa=0;aa<5;aa++)
			arr[a].marks[aa] = (a*10)+aa;
	}
	
	


	length = sizeof(cl_addr);
	fd1 = accept(sockfd, (struct sockaddr *) &cl_addr, &length);
	
	recv(fd1, &rn, sizeof(int), 0);
	int flag = 1;
	for(a=0;a<10;a++) {
		if(arr[a].roll == rn) {
			buf = arr[a];
			send(fd1, &buf, sizeof(struct student), 0);
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
		send(fd1, &buf, sizeof(struct student), 0);
	}
	

	close(fd1);


}


































