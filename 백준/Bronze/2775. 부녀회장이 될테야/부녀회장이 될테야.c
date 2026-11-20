#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[15][14] = { {0} };

	for (int i = 1; i <= 14; i++) {
		arr[0][i - 1] = i;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 0; j < 14; j++) {
			for (int k = 0; k <= j; k++) {
				arr[i][j] += arr[i - 1][k];
			}
		}
	}

	int test, k, n;

	scanf("%d\n", &test);

	for (int i = 0; i < test; i++) {
		scanf("%d\n%d", &k, &n);
		printf("%d\n", arr[k][n - 1]);
	}

	return 0;
}