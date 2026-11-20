#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	
	scanf("%d", &n);
	int* line = (int*) malloc(sizeof(int) * (n + 1));

	for (int i = 0; i < n + 1; i++) {
		line[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		int m;
		int j = 1;
		int cnt = 0;
		scanf("%d", &m);

		while (1) {
			if (cnt == m && line[j] == 0) {
				line[j] = i + 1;
				break;
			}
			else if (cnt < m && line[j] == 0) {
				j++;
				cnt++;
			}
			else {
				j++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", line[i]);
	}
	free(line);

	return 0;
}