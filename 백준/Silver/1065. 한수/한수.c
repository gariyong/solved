#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
	int N;

	scanf("%d", &N);

	if (N < 100) {
		printf("%d", N);
	}
	else {
		int count = 99;
		for (int i = 100; i <= N; i++) {
			int n_100 = i / 100, n_10 = (i % 100) / 10, n_1 = (i % 100) % 10;
			if ((n_100 - n_10) == (n_10 - n_1)) {
				count++;
			}
		}
		printf("%d", count);
	}

	return 0;
}