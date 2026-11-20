#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return *(int*)a > *(int*)b;
}

int main() {
	int n, m, value;
	
	scanf("%d", &n);
	int* num = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	qsort(num, n, sizeof(int), compare);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &value);
		int mid, left = 0, right = n - 1;
		int flag = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			if (value == num[mid]) {
				flag = 1;
				break;
			}
			if (value < num[mid]) {
				right = mid - 1; 
			}
			else {
				left = mid + 1; 
			}
		}
		printf("%d\n", flag);
	}
	free(num);

	return 0;
}