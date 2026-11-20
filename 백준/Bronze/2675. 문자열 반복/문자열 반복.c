#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int test, n;
    char arr[20];
    
    scanf("%d", &test);
    
    for(int i = 0; i < test; i++){
        scanf("%d %s", &n, &arr);
        for(int j = 0; j < strlen(arr); j++){
            for(int k = 0; k < n; k++){
                printf("%c", arr[j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}