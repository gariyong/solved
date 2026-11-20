#include <iostream>

using namespace std;

int main(){
    int t;
    
    cin >> t;
    while(t > 0){
        int n[2];
        
        cin >> n[0] >> n[1];
        cout << n[0] + n[1] << '\n';
        
        t--;
    }
    
    return 0;
}