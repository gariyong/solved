#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main()
{
	int num[5];
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &num[i]);
		sum += num[i];
	}

	qsort(num, 5, sizeof(int), compare);

	printf("%d\n%d", sum / 5, num[2]);

	return 0;
}