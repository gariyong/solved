#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "";
        return 0;
    }

    string best_path(1000001, 'Z');

    for (int m = 1; m < n; ++m) {
        if (gcd(n, m) != 1) {
            continue;
        }

        string cur_path = "";
        int a = n;
        int b = m;

        while (a > 1 || b > 1) {
            if (a > b) {
                int cnt = (a - 1) / b;
                a = a - cnt * b;
                for (int i = 0; i < cnt; ++i) {
                    cur_path += 'X';
                }
            }
            else {
                int cnt = (b - 1) / a;
                b = b - cnt * a;
                for (int i = 0; i < cnt; ++i) {
                    cur_path += 'Y';
                }
            }
        }

        reverse(cur_path.begin(), cur_path.end());

        if (cur_path.length() < best_path.length()) {
            best_path = cur_path;
        }
        else if (cur_path.length() == best_path.length() && cur_path < best_path) {
            best_path = cur_path;
        }
    }

    cout << best_path << endl;

    return 0;
}