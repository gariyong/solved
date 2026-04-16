#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1001;
vector<pair<int, int>> graph[MAX];
int visited[MAX];
int version = 1;
int result;

void dfs(int curr, int end, int dist) {
    if (curr == end) {
        result = dist;
        return;
    }
    visited[curr] = version;
    for (auto [next, cost] : graph[curr]) {
        if (visited[next] != version) {
            dfs(next, end, dist + cost);
            if (result != -1) { 
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        result = -1;
        dfs(a, b, 0);
        cout << result << '\n';
        version++;
    }

    return 0;
}