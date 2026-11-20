#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long factorial(long long n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int main() {
	long long n;

	scanf("%lld", &n);
	printf("%lld", factorial(n));

	return 0;
}