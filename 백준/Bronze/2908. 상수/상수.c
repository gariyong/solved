#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char n1[4], n2[4], box;

	scanf("%s %s", &n1, &n2);

	box = n1[0];
	n1[0] = n1[2];
	n1[2] = box;

	box = n2[0];
	n2[0] = n2[2];
	n2[2] = box;

	for (int i = 0; i < 3; i++) {
		if (n1[i] > n2[i]) {
			printf("%s", n1);
			break;
		}
		else if (n1[i] < n2[i]) {
			printf("%s", n2);
			break;
		}
	}

	return 0;
}
