#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}

int main() {
	int n, k;
	int* x;

	scanf("%d %d", &n, &k);
	x = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	qsort(x, n, sizeof(int), compare);

	printf("%d", x[k - 1]);

	return 0;
}