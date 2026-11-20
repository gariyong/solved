#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, num;
	int count[10001] = { 0 };

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		count[num] += 1;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < count[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}