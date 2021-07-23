#include<stdio.h>

int main() {

	int a = 256;
	unsigned char st[4];
	char *p = (char*)&a;

	for (int i = 0; i < 4; i++) {
		st[i] = *(p + i);
	}

	for (int i = 3; i >= 0; i--) {
		printf("%d, ", st[i]);
	}

	return 0;
}
