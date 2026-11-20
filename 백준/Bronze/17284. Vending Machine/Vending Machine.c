#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int money = 5000;
	int n;

	while (scanf("%d", &n) != EOF) {
		if (n == 1) {
			money -= 500;
		}
		else if (n == 2) {
			money -= 800;
		}
		else if (n == 3) {
			money -= 1000;
		}
	}

	printf("%d", money);

	return 0;
}