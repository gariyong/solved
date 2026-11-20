#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int n1[100][100], n2[100][100];
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &n1[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &n2[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			n1[i][j] += n2[i][j];
			printf("%d ", n1[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}