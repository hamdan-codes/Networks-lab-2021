#include<stdio.h>

int main() {

	int a = 256;
	int mask = 0xff;
	unsigned char arr[4];

	for (int i = 0; i < 4; i++) {
		arr[i] = a & mask;
		a >>= 8;
	}

	for (int i = 3; i >= 0; i--) {
		printf("%d, ", arr[i]);
	}

	return 0;
}
