#include <iostream>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int O = min(m, k);
    int X = min(n - m, n - k);

    cout << O + X;

    return 0;
}