#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	double k;
	double commission = 25;

	scanf("%lf", &k);
	commission += k * 0.01;

	if (commission < 100) {
		printf("100.00");
	}
	else if (commission < 2000) {
		printf("%.2f", commission);
	}
	else {
		printf("2000.00");
	}

	return 0;
}