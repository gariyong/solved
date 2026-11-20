#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
	return *(char*)b - *(char*)a;
}

int main() {
	char num[11] = {0};
	
	scanf("%[^\n]", &num);
	int len = strlen(num);
	
	qsort(num, len, sizeof(char), compare);

	for (int i = 0; i < len; i++) {
		printf("%c", num[i]);
	}

	return 0;
}