#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define mod 1000000007

long long pow(long long a, long long x) {
	if (x == 0) {
		return 1;
	}
	else {
		long long n = pow(a, x / 2);
		long long temp = (n * n) % mod;
		if (x % 2 == 0) {
			return temp;
		}
		else {
			return (temp * a) % mod;
		}
	}
}


int main() {
	int cnt = 1;
	long long a, x;
	
	
	scanf("%lld %lld", &a, &x);

	printf("%lld", pow(a % mod, x));

	return 0;
}