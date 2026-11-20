#include <iostream>
#include <string>

using namespace std;

int main(){
    int len;
    int cnt = 0;
    string str;
    
    cin >> len >> str;
    
    for(int i = 0; i < len; i++){
        if(str[i] == 'a' || str[i] == 'i' || str[i] == 'e' || str[i] == 'u' || str[i] == 'o'){
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}