#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct people {
	int x;
	int y;
	int num;
}people;

int main() {
	int n;
	people* member;

	scanf("%d", &n);

	member = (people*)malloc(sizeof(people) * n);
	for (int i = 0; i < n; i++) {
		member[i].num = 1;
		scanf("%d %d", &member[i].x, &member[i].y);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (member[i].x < member[j].x && member[i].y < member[j].y) {
				member[i].num++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", member[i].num);
	}
}