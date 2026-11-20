#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int arr[3];

	for (int i = 0; i < 3; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, 3, sizeof(int), compare);

	for (int i = 0; i < 3; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}