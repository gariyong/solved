#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num, n = 1, m = 1;

	scanf("%d", &num);

	while (n != 0) {
		if (num <= m) {
			printf("%d", n);
			n = 0;
		}
		else {
			m += 6 * n;
			n++;
		}
	}

	return 0;
}


