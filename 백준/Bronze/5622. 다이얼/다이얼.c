#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char arr[11][5] = { "","","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ" };
	int time = 0;
	char word[16];

	scanf("%s", &word);

	for (int i = 0; i < strlen(word); i++) {
		char letter = word[i];

		for (int j = 0; j < 11; j++) {
			if (strchr(arr[j], letter) != NULL) {
				time += j;
			}
		}
	}

	printf("%d", time);

	return 0;
}
