#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int count_len(char*);

int main()
{
	char arr[100];
	int position[26];

	for (int i = 0; i < 26; i++) {
		position[i] = -1;
	}

	scanf("%s", &arr);
	
	for (int j = 0; j < strlen(arr); j++) {
		char alphabet = arr[j];

		if (position[alphabet - 'a'] == -1) {
			position[alphabet - 'a'] = j;
		}
		else {
			continue;
		}
	}

	for (int k = 0; k < 26; k++) {
		printf("%d ", position[k]);
	}
}


