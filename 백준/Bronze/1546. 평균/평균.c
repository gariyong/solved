	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>


	int main()
	{
		int n, M= 0;
		int arr[1000];
		double sum = 0;

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] > M) {
				M = arr[i];
			}
		}

		for (int j = 0; j < n; j++) {
			sum += ((double)arr[j] / M) * 100;
		}

		printf("%f", (double)sum / n);
	}

