#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int divide(vector<vector<int>>& arr, int x, int y, int size) {
    if (size == 1) {
        return arr[x][y];
    }

    int new_size = size / 2;
    int results[4];

    results[0] = divide(arr, x, y, new_size);
    results[1] = divide(arr, x, y + new_size, new_size);
    results[2] = divide(arr, x + new_size, y, new_size);
    results[3] = divide(arr, x + new_size, y + new_size, new_size);

    sort(results, results + 4);

    return results[2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << divide(arr, 0, 0, n);

    return 0;
}