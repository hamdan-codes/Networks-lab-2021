#include<stdio.h>

int main()
{
	int i = 1;
	char *c = (char*)&i;
	if (*c == 1)
		printf("Little endian\n");
	else
		printf("Big endian\n");
	return 0;
}
