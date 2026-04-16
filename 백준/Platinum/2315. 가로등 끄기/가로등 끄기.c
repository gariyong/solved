#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

const int INF = (~0U >> 2);

int main() {
	int n, m, totall_w;
	int* lamp;
	int* w;
	int*** left_right;

	scanf("%d %d", &n, &m);

	left_right = (int***)malloc(sizeof(int**) * (n + 1));

	for (int i = 0; i <= n; i++) {
		left_right[i] = (int**)malloc(sizeof(int*) * (n + 1));
		for (int j = 0; j <= n; j++) {
			left_right[i][j] = (int*)malloc(sizeof(int) * 2);
			left_right[i][j][0] = 0;
			left_right[i][j][1] = 0;
		}
	}

	lamp = (int*)malloc(sizeof(int) * n + 1);
	w = (int*)malloc(sizeof(int*) * n + 1);
	lamp[0] = 0;
	w[0] = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &lamp[i], &w[i]);
		w[i] += w[i - 1];
	}

	totall_w = w[n];
	int right = n - 1;

	for (int left = 1; left <= m; left++) {
		for (right; right >= m; right--) {
			int left_min = INF, right_min = INF;
			int waste_w = totall_w - (w[right] - w[left - 1]);

			if (left != 1) {
				if (left_min > left_right[left - 1][right][0] + waste_w * (lamp[left] - lamp[left - 1])) {
					left_min = left_right[left - 1][right][0] + waste_w * (lamp[left] - lamp[left - 1]);
				}
				if (right_min > left_right[left - 1][right][0] + waste_w * (lamp[right] - lamp[left - 1])) {
					right_min = left_right[left - 1][right][0] + waste_w * (lamp[right] - lamp[left - 1]);
				}
			}
			if (right != n) {
				if (left_min > left_right[left][right + 1][1] + waste_w * (lamp[right + 1] - lamp[left])) {
					left_min = left_right[left][right + 1][1] + waste_w * (lamp[right + 1] - lamp[left]);
				}
				if (right_min > left_right[left][right + 1][1] + waste_w * (lamp[right + 1] - lamp[right])) {
					right_min = left_right[left][right + 1][1] + waste_w * (lamp[right + 1] - lamp[right]);
				}
			}
			left_right[left][right][0] = left_min;
			left_right[left][right][1] = right_min;
		}
		right = n;
	}

	if (left_right[m][m][0] < left_right[m][m][1]) {
		printf("%d", left_right[m][m][0]);
	}
	else {
		printf("%d", left_right[m][m][1]);
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			free(left_right[i][j]);
		}
		free(left_right[i]);
	}
	free(left_right);

	return 0;
}