#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	char** name;

	scanf("%d", &n);
	name = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		name[i] = (char*)malloc(sizeof(char) * 21);
		scanf("\n%[^\n]", name[i]);
		int len = strlen(name[i]);

		for (int j = 0; j < len; j++) {
			if (name[i][j] >= 'A' && name[i][j] <= 'Z') {
				name[i][j] += 'a' - 'A';
			}
			printf("%c", name[i][j]);
		}
		printf("\n");
	}

	return 0;
}