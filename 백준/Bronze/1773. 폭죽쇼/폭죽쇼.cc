#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<bool> firework(c + 1, false);

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        for (int j = t; j <= c; j += t) {
            firework[j] = true;
        }
    }

    int result = 0;
    for (int i = 1; i <= c; ++i) {
        if (firework[i]) ++result;
    }

    cout << result << '\n';
    return 0;
}
