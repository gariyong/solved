#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int arr[9][9];
	int n, m, max = -1;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] > max) {
				max = arr[i][j];
				n = i; 
				m = j;
			}
		}
	}

	printf("%d\n%d %d", arr[n][m], n+1, m+1);

	return 0;
}