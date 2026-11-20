#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int inner = n - (m - 2);
    int next = 1;

    for (int i = 0; i < inner - 1; i++) {
        printf("%d %d\n", i, i + 1);
        next++;
    }

    for (int i = 0; i < (m - 2); i++) {
        printf("%d %d\n", inner - 2, next);
        next++;
    }

    return 0;
}