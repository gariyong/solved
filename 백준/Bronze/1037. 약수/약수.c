#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int n;
	int* factors;

	scanf("%d", &n);
	factors = (int*)malloc(4 * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &factors[i]);
	}
	qsort(factors, n, 4, compare);

	if (n == 1) {
		printf("%d", factors[0] * factors[0]);
	}
	else {
		printf("%d", factors[0] * factors[n - 1]);
	}

	return 0;
}