#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n, m;
	int answer = 0;
	int* tree;
	int high = 0, low = 0;

	scanf("%d %d", &n, &m);
	tree = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tree[i]);
		if (high < tree[i]) {
			high = tree[i];
		}
	}

	while (low <= high) {
		int mid = (high + low) / 2;
		long long sum = 0;

		for (int i = 0; i < n; i++) {
			if(tree[i] >= mid){
				sum += tree[i] - mid;
			}
		}

		if (sum >= m) {
			if (mid > answer) {
				answer = mid;
			}

			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	printf("%d", answer);
	free(tree);

	return 0;
}