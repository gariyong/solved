	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

int main()
{
	int count;

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		for (int k = i+1; k < count; k++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
