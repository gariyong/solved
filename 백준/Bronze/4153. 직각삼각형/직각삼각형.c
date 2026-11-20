#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int side[3];

	while (1)
	{
		scanf("%d %d %d", &side[0], &side[1], &side[2]);
		if (side[0] == 0) {
			break;
		}
		qsort(side, 3, 4, compare);

		for (int i = 0; i < 3; i++) {
			side[i] *= side[i];
		}

		if (side[2] == (side[0] + side[1])) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}
	
	return 0;
}