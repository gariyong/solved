#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main(void)
{
	int arr[100] = { 0 };
	int n, m, k, l, j;

	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &k, &l, &j);
		for (; k <= l; k++)
		{
			arr[k - 1] = j;
		}
	}

	for (int h = 0; h<m; h++)
	{
		printf("%d ", arr[h]);
	}
}
