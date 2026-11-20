#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    if (n == 1) {
        cout << 0;
    }
    else if ((x == 1 && y == 1) || (x == 1 && y == n) || (x == n && y == 1) || (x == n && y == n)) {
        cout << 2;
    }
    else if (x == 1 || x == n || y == 1 || y == n) {
        cout << 3;
    }
    else {
        cout << 4;
    }

    return 0;
}