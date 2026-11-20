#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, c, d;
	
	scanf("%d%d", &a, &b);

	c = b % 10;
	d = b / 100;

	printf("%d\n", a * c);
	printf("%d\n", a*(b-c-d*100)/10);
	printf("%d\n", a * d);
	printf("%d", a * b);

	return 0;
}