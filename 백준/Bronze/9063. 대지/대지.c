#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, min_x = 10001, max_x = -10001, min_y = 10001, max_y = -10001;
	
	scanf("%d", &n);
	
	int* x = (int*)malloc(n * 4);
	int* y = (int*)malloc(n * 4);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}

	if (n == 1) {
		printf("0");
	}
	else {
		for (int i = 0; i < n; i++) {
			if (max_x < x[i]) {
				max_x = x[i];
			}
			if (min_x > x[i]) {
				min_x = x[i];
			}
			if (max_y < y[i]) {
				max_y = y[i];
			}
			if (min_y > y[i]) {
				min_y = y[i];
			}
		}

		printf("%d", (max_x - min_x) * (max_y - min_y));
	}

	free(x);
	free(y);

	return 0;
}