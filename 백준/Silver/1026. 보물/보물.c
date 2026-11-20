#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int compare(int* a, int* b) {
	return (*a - *b);
}

int main()
{
	int n, sum = 0;
	
	scanf("%d", &n);

	int* a;
	int* b;

	a = (int*)malloc(4 * n);
	b = (int*)malloc(4 * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}

	qsort(a, n, 4, compare);
	qsort(b, n, 4, compare);

	for (int i = 0; i < n; i++) {
		sum += a[i] * b[n - i - 1];
	}

	printf("%d", sum);

	free(a);
	free(b);
	
	return 0;
}