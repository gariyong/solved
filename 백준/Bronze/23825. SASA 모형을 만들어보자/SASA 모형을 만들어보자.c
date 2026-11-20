#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	long n, m;

	scanf("%ld %ld", &n, &m);

	n /= 2;
	m /= 2;

	if (n > m) {
		printf("%d", m);
	}
	else if (n < m) {
		printf("%d", n);
	}
	else {
		printf("%d", n);
	}

	return 0;
}