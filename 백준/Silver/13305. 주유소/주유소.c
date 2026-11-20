#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int* dis;
	int* price;
	long sum = 0;

	scanf("%d", &n);

	dis = (int*)malloc(4 * (n - 1));
	price = (int*)malloc(4 * n);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &dis[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &price[i]);
	}

	long min_cost = price[0];

	for (int i = 0; i < n - 1; i++) {
		if (min_cost > price[i]) {
			min_cost = price[i];
		}
		sum += (min_cost * dis[i]);
	}
	free(dis);
	free(price);

	printf("%ld", sum);

	return 0;
}