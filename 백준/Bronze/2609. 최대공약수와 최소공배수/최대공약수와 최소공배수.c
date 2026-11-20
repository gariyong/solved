#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n1, n2, num = 1, i =2;

	scanf("%d %d", &n1, &n2);
	while (1) {
		if (n1 < i || n2 < i) {
			break;
		}
		if ((n1 % i == 0) && (n2 % i == 0)) {
			num *= i;
			n1 /= i;
			n2 /= i;
		}
		else {
			i++;
		}
	}

	printf("%d\n%d", num, num * n1 * n2);

	return 0;
}