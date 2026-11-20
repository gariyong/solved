#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
vector<int> cur;
vector<bool> used;

void backtrack() {
    if (cur.size() == m) {
        for (int i = 0; i < m; i++) {
            cout << cur[i] << ' ';
        }
        cout << '\n';

        return;
    }

    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        if (v[i] == prev) {
            continue;
        }

        used[i] = true;
        cur.push_back(v[i]);
        backtrack();
        cur.pop_back();
        used[i] = false;
        prev = v[i];
    }
}

int main() {
    cin >> n >> m;

    v.resize(n);
    used.resize(n, false);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    backtrack();

    return 0;
}