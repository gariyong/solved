#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    double result, w, h;
    
    scanf("%lf %lf", &w, &h);
    result = (w*h)/2;
    
    printf("%.1f", result);
    
    return 0;
}