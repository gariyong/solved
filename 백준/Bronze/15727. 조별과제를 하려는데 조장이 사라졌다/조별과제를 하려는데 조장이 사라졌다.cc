#include <iostream>

using namespace std;

int main(){
 int len;
    
    cin >> len;
    if(len%5 == 0){
cout << len/5;
}else{
cout << len/5 + 1;
}
    return 0;
}