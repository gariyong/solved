#include <iostream>

using namespace std;

const double PI = 3.141592;

int main() {
    int d1, d2;
    cin >> d1 >> d2;
    double result = d1 * 2 + 2 * PI * d2;
  
    cout << fixed;
    cout.precision(6);
    cout << result << "\n";
    
    return 0;
}