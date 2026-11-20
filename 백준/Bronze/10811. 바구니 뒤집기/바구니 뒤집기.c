#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int arr[100];
	int n, m, num;
	int j, l;

	for (int i = 0; i < 100; i++) {
		arr[i] = i + 1;
	}

	scanf("%d %d", &n, &m);

	for (int k = 0; k < m; k++) {
		scanf("%d %d", &j, &l);
		int count = (l - j) / 2 + 1;
		for (; count > 0;count--) {
			if (j < l) {
				num = arr[l - 1];
				arr[l - 1] = arr[j - 1];
				arr[j - 1] = num;
				j++;
				l--;
			}
		}
	}

	for (int p = 0; p < n; p++) {
		printf("%d ", arr[p]);
	}
}