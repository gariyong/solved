#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    long long x, y;
    cin >> x >> y;

    int z = (y * 100) / x;

    if (z >= 99) {
        cout << -1 << "\n";
        return 0;
    }

    long long left = 1;
    long long right = 1e9;
    long long cur = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;
        int new_z = ((y + mid) * 100) / (x + mid);

        if (new_z > z) {
            cur = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << cur << "\n";

    return 0;
}