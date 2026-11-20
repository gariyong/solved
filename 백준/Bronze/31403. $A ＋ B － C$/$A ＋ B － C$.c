#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	printf("%d\n", a + b - c);

	if (b < 10) {
		printf("%d", a * 10 + b - c);
	}
	else if (b < 100) {
		printf("%d", a * 100 + b - c);
	}else if(b<1000){
		printf("%d", a * 1000 + b - c);
	}
	else {
		printf("%d", a * 10000 + b - c);
	}

	return 0;
}