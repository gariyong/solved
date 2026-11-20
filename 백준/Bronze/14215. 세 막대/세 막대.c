#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y, z;

	scanf("%d %d %d", &x, &y, &z);

	if (x >= y + z) {
		x = y + z - 1;
	}
	else if (y >= x + z) {
		y = x + z - 1;
	}
	else if (z >= x + y) {
		z = x + y - 1;
	}
	printf("%d", x + y + z);

	return 0;
}