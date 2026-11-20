#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char word[101];
	int alphabat[26] = { 0 };

	scanf("%[^\n]", &word);

	for (int i = 0; i < strlen(word); i++) {
		alphabat[word[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", alphabat[i]);
	}

	return 0;
}