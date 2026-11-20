	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

int main()
{
	int x, n;
	int arr[10000];

	scanf("%d %d", &n, &x);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] < x) {
			printf("%d ", arr[i]);
		}
	}
}
