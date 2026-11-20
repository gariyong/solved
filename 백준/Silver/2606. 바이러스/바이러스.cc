#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

void unite(vector<int>& parent, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    while (m--) {
        int a, b;
        cin >> a >> b;
        unite(parent, a, b);
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (find(parent, i) == find(parent, 1)) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}