#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, max_len = 0;
	int* sequence;
	int* len;

	scanf("%d", &n);
	
	sequence = (int*)malloc(sizeof(int) * n);
	len = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &sequence[i]);
	}

	for (int i = 0; i < n; i++) {
		len[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			if (sequence[j] < sequence[i] && len[j] >= len[i]) {
				len[i] = len[j] + 1;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (max_len < len[i]) {
			max_len = len[i];
		}
	}

	free(len);
	free(sequence);

	printf("%d", max_len);

	return 0;
}