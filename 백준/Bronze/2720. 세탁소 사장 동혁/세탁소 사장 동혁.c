#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int Quarter = 25, Dime = 10, Nickel = 5, Penny = 1;
	int cost, n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &cost);

		int Q_n = 0, D_n = 0, N_n = 0, P_n = 0;

		Q_n = cost / Quarter;
		cost %= Quarter;
		D_n = cost / Dime;
		cost %= Dime;
		N_n = cost / Nickel;
		cost %= Nickel;
		P_n = cost / Penny;

		printf("%d %d %d %d\n", Q_n, D_n, N_n, P_n);
	}

	return 0;
}


