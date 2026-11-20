#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	long long a, b, c;

	scanf("%lld %lld %lld", &a, &b, &c);

	if (c - b <= 0) {
		printf("-1");
	}
	else{
		printf("%lld", a / (c - b) + 1);
	}

	return 0;
}