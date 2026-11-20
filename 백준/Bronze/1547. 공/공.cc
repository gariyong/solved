#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    int pos = 1;
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        
        if (pos == a) pos = b;
        else if (pos == b) pos = a;
    }

    cout << pos;
    
    return 0;
}