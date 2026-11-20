#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, h, day;

	scanf("%d %d %d", &a, &b, &h);
	
	day = (h - b - 1) / (a - b) + 1;

	printf("%d", day);

	return 0;
}
