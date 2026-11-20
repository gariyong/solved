#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, k, sum = 1;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		sum *= n - i;
	}
	for (int i = 0; i < k; i++) {
		sum /= k - i;
	}
	for (int i = 0; i < (n - k); i++) {
		sum /= (n - k) - i;
	}

	printf("%d", sum);

	return 0;
}