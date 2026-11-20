#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int n, x, cnt = 0;
	int* num;

	scanf("%d", &n);
	
	num = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	qsort(num, n, sizeof(int), compare);

	scanf("%d", &x);

	int left_p = 0, right_p = n - 1;
	
	while (left_p < right_p) {
		if (num[left_p] + num[right_p] == x) {
			cnt++;
			if (num[left_p + 1] - num[left_p] < num[right_p] - num[right_p - 1]) {
				left_p++;
			}
			else {
				right_p--;
			}
		}
		else if (num[left_p] + num[right_p] < x) {
			left_p++;
		}
		else if (num[left_p] + num[right_p] > x) {
			right_p--;
		}
	}

	free(num);

	printf("%d", cnt);

	return 0;
}