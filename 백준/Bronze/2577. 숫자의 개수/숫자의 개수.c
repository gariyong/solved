#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int A, B, C, num, arr[10] = { 0 }, n = 1;

	scanf("%d %d %d", &A, &B, &C);
	num = A * B * C;

	while (num / n != 0) {
		arr[(num / n)%10]++;
		n *= 10;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}