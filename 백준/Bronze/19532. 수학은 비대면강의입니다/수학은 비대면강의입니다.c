#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, c, d, e, f;
	int x, y;

	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	for (x = -999; x <= 999; x++) {
		for (y = -999; y <= 999; y++) {
			if (a * x + b * y == c && d * x + e * y == f) {
				printf("%d %d", x, y);
				break;
			}
		}
	}

	return 0;
}

