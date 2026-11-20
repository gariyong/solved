#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int n;

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < n - i; k++) {
			printf(" ");
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n-1; i >0; i--) {
		for (int j = 0; j < n - i; j++) {
			printf(" ");
		}
		for (int j = 0; j < i*2-1; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
