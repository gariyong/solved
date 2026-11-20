#include <iostream>

using namespace std;

int main() {
    int h, m, s, d;
    
    cin >> h >> m >> s;
    cin >> d;

    int total = h * 3600 + m * 60 + s + d;

    total %= 86400;
    h = total / 3600;
    m = (total % 3600) / 60;
    s = total % 60;

    cout << h << " " << m << " " << s << endl;
    
    return 0;
}