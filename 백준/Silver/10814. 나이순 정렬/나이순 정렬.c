#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct people {
	char name[101];
	int age;
}people;

int compare(const void* a, const void* b){
	people member_1 = *(people*)a;
	people member_2 = *(people*)b;

	if (member_1.age > member_2.age) {
		return 1;
	}
	else if (member_1.age < member_2.age) {
		return -1;
	}
	else {
		return 0;
	}
}

int main() {
	int n;
	

	scanf("%d", &n);
	people* member = (people*)malloc(sizeof(people) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d %[^\n]", &member[i].age, &member[i].name);
	}

	qsort(member, n, sizeof(people), compare);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n", member[i].age, member[i].name);
	}
	free(member);

	return 0;
}