#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, a, b;
	int n1 = 100, n2 = 100;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (a > b) {
			n2 -= a;
		}
		else if (b > a) {
			n1 -= b;
		}
	}

	printf("%d\n%d", n1, n2);

	return 0;
}