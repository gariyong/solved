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
        parent[a] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int g, p;
    cin >> g >> p;

    vector<int> gates(g + 1);
    for (int i = 0; i <= g; i++) gates[i] = i;

    int cnt = 0;
    while (p--) {
        int g_i;
        cin >> g_i;

        int gate = find(gates, g_i);
        if (gate == 0) break;

        unite(gates, gate, gate - 1);
        cnt++;
    }

    cout << cnt;

    return 0;
}