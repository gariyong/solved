#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct discussion
{
	int start;
	int end;
}discussion; 

int compare(const void* a, const void* b);

int main()
{
	int n, last_time = 0, count = 0;
	discussion* time_table;

	scanf("%d", &n);

	time_table = (discussion*)malloc(sizeof(discussion) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &time_table[i].start, &time_table[i].end);
	}

	qsort(time_table, n, sizeof(discussion), compare);
	for (int i = 0; i < n; i++) {
		if (time_table[i].start >= last_time) {
			count++;
			last_time = time_table[i].end;
		}
	}

	free(time_table);
	printf("%d", count);

	return 0;
}

int compare(const void* a, const void* b) {
	const discussion* t1, * t2;
	t1 = (const discussion*)a;
	t2 = (const discussion*)b;

	if (t1->end != t2->end) {
		if (t1->end < t2->end) {
			return -1;
		}
		else if (t1->end == t2->end) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		if (t1->start < t2->start) {
			return -1;
		}
		else if (t1->start == t2->start) {
			return 0;
		}
		else {
			return 1;
		}
	}
}
