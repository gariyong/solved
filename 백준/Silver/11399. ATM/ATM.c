#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);

int main()
{
	int n, total = 0;
	int* p_time;

	scanf("%d", &n);
	
	p_time = (int*)calloc(n, 4);

	for (int i = 0; i < n; i++) {
		scanf("%d", &p_time[i]);
	}
	qsort(p_time, n, 4, compare);

	for (int i = 0; i < n; i++) {
		total += p_time[i] * (n - i);
	}

	free(p_time);
	printf("%d", total);

	return 0;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}