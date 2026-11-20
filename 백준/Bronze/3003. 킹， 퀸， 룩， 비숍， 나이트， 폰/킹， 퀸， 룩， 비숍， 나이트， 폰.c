#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int chess[6] = { 1, 1, 2, 2, 2, 8 };
	int count;

	for (int i = 0; i < 6; i++) {
		scanf("%d", &count);
		chess[i] -= count;
	}

	for (int j = 0; j < 6; j++) {
		printf("%d ", chess[j]);
	}

	return 0;
}
