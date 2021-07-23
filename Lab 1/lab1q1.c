#include<stdio.h>

int main() {

	int a = 1, b = 2;
	printf("a = %d, b = %d\n", a, b);

	int *aptr = &a;
	int *bptr = &b;

	int temp = *aptr;
	*aptr = *bptr;
	*bptr = temp;

	printf("a = %d, b = %d\n", a, b);

	return 0;
}
