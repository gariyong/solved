#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y, w, h, len;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	len = x;
	if (len > y) {
		len = y;
	}
	if (len > w - x) {
		len = w - x;
	}
	if (len > h - y) {
		len = h - y;
	}
	

	printf("%d", len);

	return 0;
}
