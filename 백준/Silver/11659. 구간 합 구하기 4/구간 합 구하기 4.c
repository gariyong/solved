#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	int* arr;

	scanf("%d %d", &n, &m);
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i < n; i++) {
		arr[i] = arr[i] + arr[i - 1];
	}

	for (int i = 0; i < m; i++) {
		int j, k;
		scanf("%d %d", &j, &k);

		if (j == 1) {
			printf("%d\n", arr[k - 1]);
		}
		else {
			printf("%d\n", arr[k - 1] - arr[j - 2]);
		}
	}
	free(arr);

	return 0;
}