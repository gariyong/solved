#include <iostream>

using namespace std;

int main(){
    int n;

    while(cin >> n){
        if(n == 0){
        break;
        }
    else{
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j > 0; j--){
                cout << "*";
                }
            cout << "\n";
            }
        }
    }

return 0;
}