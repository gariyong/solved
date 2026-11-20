	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

int main()
{
	int arr[100];
	int n, num, count = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &num);

	for (int k = 0; k < n; k++) {
		if (num == arr[k]) {
			count += 1;
		}
	}
	printf("%d", count);
}
