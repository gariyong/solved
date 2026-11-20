#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int find(int);

int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		if (find(i) == N) {
			printf("%d\n", i);
			break;
		}
		if (i == N) {
			printf("%d\n", 0);
		}
	}

	return 0;
}

int find(int n) 
{
	int num = n;

	while (n > 0) {
		num = num + (n % 10);
		n /= 10;
	}

	return num;
}
