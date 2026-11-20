#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, f;

	scanf("%d", &n);
	n -= n % 100;
	scanf("%d", &f);
	if (n % f != 0) {
		n += f - (n % f);
	}
	if (n % 100 < 10) {
		printf("0%d", n % 10);
	}
	else {
		printf("%d", n % 100);
	}

	return 0;
}