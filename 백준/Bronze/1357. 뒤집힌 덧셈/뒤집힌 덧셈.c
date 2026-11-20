#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swap(char* num) {
    int len = strlen(num);
    for (int i = 0; i < len / 2; i++) {
        char temp;
        temp = num[i];
        num[i] = num[len - i - 1];
        num[len - i - 1] = temp;
    }
    return atoi(num);
}

int main() {
    char n1[5], n2[5], sum_c[5];
    int sum;

    scanf("%s\n%s", &n1, &n2);
    sum = swap(n1) + swap(n2);
    sprintf(sum_c, "%d", sum);

    printf("%d", swap(sum_c));

    return 0;
}