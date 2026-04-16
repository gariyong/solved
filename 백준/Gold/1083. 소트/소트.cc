#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int s;
    cin >> s;

    for (int i = 0; i < n - 1 && s > 0; i++) {
        int max_idx = i;

        for (int j = i + 1; j < n && j - i <= s; j++) {
            if (num[j] > num[max_idx]) {
                max_idx = j;
            }
        }

        int dist = max_idx - i;
        s -= dist;

        for (int j = max_idx; j > i; j--) {
            swap(num[j], num[j - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << num[i] << ' ';
    }

    return 0;
}