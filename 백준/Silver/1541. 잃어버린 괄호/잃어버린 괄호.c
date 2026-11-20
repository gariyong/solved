#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char math[51];
	char num[6];
	int i = 0, j = 0, count = 0, sum = 0;
	
	scanf("%s", math);

	while (math[i] != NULL) {
		if (math[i] == '-' || math[i] == '+') {
			if (count == 1) {
				sum -= atoi(num);
				memset(num, NULL, 6);
				j = 0;
			}
			else {
				sum += atoi(num);
				memset(num, NULL, 6);
				j = 0;
			}
			if (math[i] == '-') {
				count = 1;
			}
		}
		else {
			num[j] = math[i];
			j++;
		}
		i++;
	}
	if (count == 1) {
		sum -= atoi(num);
	}
	else {
		sum += atoi(num);
	}
	

	printf("%d", sum);

	return 0;
}