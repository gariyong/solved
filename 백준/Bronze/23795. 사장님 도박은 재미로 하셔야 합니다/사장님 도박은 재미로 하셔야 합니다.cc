#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int sum = 0;
    int x;
    
    while(true){
        cin >> x;
        
        if(x == -1){
            break;
        }
        
        sum +=x;
    }
    
    cout << sum;
}