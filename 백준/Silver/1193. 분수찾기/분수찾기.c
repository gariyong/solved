#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, m = 1, i;

	scanf("%d", &n);

	for (i = 1; n > m;) {
		m += ++i;
	}

	if (i % 2 == 0) {
		printf("%d/%d", i - (m - n), 1 + (m - n));
	}
	else {
		printf("%d/%d", 1 + (m - n), i - (m - n));
	}

	return 0;
}
