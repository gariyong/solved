#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	char* code;
	long long hash = 0, M = 1234567891, m = 1;

	scanf("%d", &n);
	code = (char*)malloc(n);
	for (int i = 0; i < n; i++) {
		scanf("\n%c", &code[i]);
		hash = (hash + (code[i] - 'a' + 1) * m) % M;
		m = (m * 31) % M;
	}

	printf("%lld", hash);

	return 0;
}