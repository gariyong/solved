	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>


	int main()
	{
		char sentence[1001];
		int i;

		scanf("%s", &sentence);
		scanf("%d", &i);

		printf("%c", sentence[i - 1]);

		return 0;
	}

