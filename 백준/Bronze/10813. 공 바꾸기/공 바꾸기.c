#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int*, int*);

int main()
{
	int arr[100];
	int n, m, n1, n2;

	for (int i = 1; i <= 100; i++) {
		arr[i-1] = i;
	}

	scanf("%d %d", &m, &n);

	for (; n > 0; n--) {
		scanf("%d %d", &n1, &n2);
		swap(&arr[n1-1], &arr[n2-1]);
	}

	for (int j = 0; j < m; j++) {
		printf("%d ", arr[j]);
	}


}

void swap(int* n1, int* n2)
{
	int num = 0;
	num = *n1;
	*n1 = *n2;
	*n2 = num;
}