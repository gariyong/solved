#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>

#define money 1000

int main() {
	int cost, coin = 0;

	scanf("%d", &cost);

	cost = money - cost;

	coin += cost / 500;
	cost %= 500;
	coin += cost / 100;
	cost %= 100;
	coin += cost / 50;
	cost %= 50;
	coin += cost / 10;
	cost %= 10;
	coin += cost / 5;
	coin += cost % 5;

	printf("%d", coin);

	return 0;
}