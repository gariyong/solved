#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int H, M, time, h, m;

	scanf("%d%d%d", &H, &M, &time);
	
	h = time / 60;
	m = time % 60;
	
	if ((M + m) > 59) {
		M = (M + m) - 60;
		H += 1;
	}
	else {
		M += m;
	}
	if ((H + h) > 23) {
		H = (H + h) - 24;
	}
	else {
		H += h;
	}

	printf("%d %d", H, M);

	return 0;

}