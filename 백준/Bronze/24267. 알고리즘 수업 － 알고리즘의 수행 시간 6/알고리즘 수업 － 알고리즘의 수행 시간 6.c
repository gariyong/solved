#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	long n;

	scanf("%ld", &n);

	printf("%ld\n3", n * (n-1) * (n-2)/6);

	return 0;
}