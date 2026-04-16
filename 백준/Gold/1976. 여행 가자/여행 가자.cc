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
    for (int i = 0; i <= n; i++) parent[i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            
            if (x == 1) {
                unite(parent, i, j);
            }
        }
    }

    vector<int> plan(m);
    for (int i = 0; i < m; i++) cin >> plan[i];

    bool possible = true;
    int root = find(parent, plan[0]);

    for (int i = 1; i < m; i++) {
        if (find(parent, plan[i]) != root) {
            possible = false;
            break;
        }
    }

    cout << (possible ? "YES" : "NO");

    return 0;
}