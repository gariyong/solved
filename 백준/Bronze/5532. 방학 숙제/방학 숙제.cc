#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;

    int korean = (a + c - 1) / c;
    int math = (b + d - 1) / d;
    int study = max(korean, math);
    
    cout << l - study;

    return 0;
}