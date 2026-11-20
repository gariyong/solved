#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int arr[100][100] = {0, };
	int n, x, y, count = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				arr[x + j][y+k] = 1;
			}
		}
	}
	for (int x = 0; x < 100; x++) {
		for (int y = 0; y < 100; y++) {
			if (arr[x][y] == 1) {
				count++;
			}
		}
	}

	printf("%d", count);

	return 0;
}