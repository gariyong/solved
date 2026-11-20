#include <stdio.h>

int main(){
    long long n, m;
    scanf("%lld %lld", &n, &m);
    
    if(n<m){
        printf("%lld", m-n);
    }
    else{
        printf("%lld", n-m);
    }
    
    return 0;
}