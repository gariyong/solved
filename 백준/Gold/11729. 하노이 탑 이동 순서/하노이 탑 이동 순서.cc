#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void hanoi(int n, int from, int to, int by) {
    if (n == 1) {
        cout << from << " " << to << '\n';
        return;
    }

    hanoi(n - 1, from, by, to);
    cout << from << " " << to << '\n';
    hanoi(n - 1, by, to, from);
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int k = pow(2, n) - 1;
    cout << k << '\n';

    hanoi(n, 1, 3, 2);

    return 0;
}