#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int cost;
	int sum = 0;
	int count, n1, n2;

	scanf("%d %d", &cost, &count);

	for (int i = 0; i < count; i++)
	{
		scanf("%d %d", &n1, &n2);
		sum += (n1 * n2);
	}

	if (sum == cost) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	
	return 0;
}
