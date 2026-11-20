#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n = 2, m = 1, count;

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		n += m;
		m *= 2;
	}

	printf("%d", n * n);

	return 0;
}


