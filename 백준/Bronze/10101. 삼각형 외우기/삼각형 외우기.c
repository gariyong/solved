#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int st1, st2, st3;

	scanf("%d %d %d", &st1, &st2, &st3);

	if ((st1 + st2 + st3) != 180) {
		printf("Error");
	}
	else if (st1 == st2 && st2 == st3) {
		printf("Equilateral");
	}
	else if (st1 == st2 || st2 == st3 || st1 == st3) {
		printf("Isosceles");
	}
	else {
		printf("Scalene");
	}

	return 0;
}