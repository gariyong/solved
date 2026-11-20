#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, m, sum = 0;
	int min = 100001;
	

	scanf("%d %d", &n, &m);

	for (n; n <= m; n++) {
		int check = -1;

		for (int i = 1; i < n; i++) {
			if (i != 1 && n % i == 0) {
				check = 0;
				break;
			}
			check = 1;
		}
		if (check == 1) {
			sum += n;
			if (n < min) {
				min = n;
			}
		}
	}

	if (sum == 0) {
		printf("-1");
	}
	else {
		printf("%d\n%d", sum, min);
	}

	return 0;
}
