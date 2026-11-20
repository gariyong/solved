#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	while (1) {
		int n, sum = 0;
		int* arr;
		int count = 0, k = 0;

		scanf("%d", &n);

		if (n == -1) {
			break;
		}

		for (int i = 1; i <= n; i++) {
			if (i == n) {
				break;
			}
			else if (n % i == 0) {
				sum += i;
				k++;
			}
		}

		arr = (int*)malloc(sizeof(int) * k);

		if (sum != n) {
			printf("%d is NOT perfect.", n);
		}
		else {
			for (int i = 1; i < n; i++) {
				if (n % i == 0) {
					arr[count] = i;
					count++;
				}
			}
			printf("%d = %d ", n, arr[0]);
			for (int i = 1; i < count; i++) {
				printf("+ %d ", arr[i]);
			}
		}
		printf("\n");
	}

	return 0;
}
