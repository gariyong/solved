#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n1, n2, n3, sum;

	scanf("%d%d%d", &n1, &n2, &n3);

	if (n1 == n2 && n2 == n3) {
		sum = 10000 + 1000 * n1;
	}
	else if (n1 == n2 || n1 == n3) {
		sum = 1000 + 100 * n1;
	}
	else if (n2 == n3) {
		sum = 1000 + 100 * n2;
	}
	else if (n1 > n2 && n1 > n3) {
		sum = 100 * n1;
	}
	else if (n2 > n1 && n2 > n3) {
		sum = n2 * 100;
	}
	else if (n3 > n1 && n3 > n2) {
		sum = n3 * 100;
	}

	printf("%d", sum);

	return 0;
}