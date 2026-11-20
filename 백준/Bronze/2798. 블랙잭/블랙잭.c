#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m;
	int blackjack = 0;

	scanf("%d %d", &n, &m);

	int* cards = (int*)malloc(4 * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cards[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n ; j++) {
			for (int k = j+1; k < n; k++) {
				int sum = cards[i] + cards[j] + cards[k];
				if (sum > blackjack && sum <= m) {
					blackjack = sum;
				}
			}
		}
	}
	free(cards);

	printf("%d\n", blackjack);

	return 0;
}