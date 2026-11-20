#include <iostream>

using namespace std;

int main(){
    int k, n, m;
    
    cin >> k >> n >>m;
    int price = k*n;
    int result = price - m;
    
    cout << (result > 0 ? result : 0);
    
    return 0;
}