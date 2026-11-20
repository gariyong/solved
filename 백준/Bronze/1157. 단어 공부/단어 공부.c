#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	


int main()
{
	char word[1000001];
	int alphabet[26]={0}, num, max = -1, n = 0, m;

	scanf("%s", &word);

	int len = strlen(word);

	for (int i = 0; i < len; i++) {
		if (word[i] >= 'a' && word[i] <= 'z') {
			word[i] -= 'a' - 'A';
		}
		num = word[i] - 'A';
		alphabet[num]++;
	}
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > max) {
			max = alphabet[i];
			n = 1;
			m = i;
		}
		else if (n != 0 && alphabet[i] == max) {
			n++;
		}
		
	}
	if (n == 1) {
		printf("%c", 'A' + m);
	}
	else {
		printf("?");
	}

	return 0;
}
