#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int n;
	int* num;

	scanf("%d", &n);
	num = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	qsort(num, n, 4, compare);

	for (int i = 0; i < n; i++) {
		printf("%d\n", num[i]);
	}
	free(num);

	return 0;
}