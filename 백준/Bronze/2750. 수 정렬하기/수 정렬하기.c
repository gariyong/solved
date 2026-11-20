
#include <stdio.h>
 
int main(){
    int N;
    scanf("%d", &N);
 
    int len = N;
    int arr[len];
    for(int i=0; i<len; i++){
        scanf("%d", &arr[i]);
    }
 
    // Bubble Sort
    while(1){
        int swapped = 0;
        for(int i=0; i<N-1; i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = 1;
            }
        }
        if(!swapped)
            break;
        N = N-1;
    }
 
    for(int i=0; i<len; i++){
        printf("%d\n", arr[i]);
    }
}