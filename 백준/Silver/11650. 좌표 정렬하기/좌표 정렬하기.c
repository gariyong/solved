#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate {
	int x;
	int y;
}coordinate;

int compare(const void* a, const void* b) {
	coordinate p1 = *(coordinate*)a;
	coordinate p2 = *(coordinate*)b;

	if (p1.x > p2.x) {
		return 1;
	}
	else if (p1.x < p2.x) {
		return -1;
	}
	else if (p1.x == p2.x) {
		if (p1.y > p2.y) {
			return 1;
		}
		else if (p1.y < p2.y) {
			return -1;
		}
		else {
			return 0;
		}
	}
}

int main() {
	int n;

	scanf("%d", &n);
	coordinate* point = (coordinate*)malloc(sizeof(coordinate) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &point[i].x, &point[i].y);
	}
	qsort(point, n, sizeof(coordinate), compare);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", point[i].x, point[i].y);
	}
	free(point);
	
	return 0;
}