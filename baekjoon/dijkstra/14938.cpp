// 문제: https://www.acmicpc.net/problem/14938
// 제목: 서강그라운드

#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>
#include <functional>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;

void djikstra(const Graph& graph, vector<int>& item, int start, int m) {
    vector<int> dist(graph.size(), INF);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost > dist[cur]) continue;

        for (auto& [n_cost, next] : graph[cur]) {
            int new_cost = cost + n_cost;

            if (dist[next] > new_cost && new_cost <= m) {
                dist[next] = new_cost;
                pq.push({ new_cost, next });
            }
        }
    }

    for (int i = 1; i < item.size(); i++) {
        if (dist[i] > m) {
            item[i] = 0;
        }
    }
}

int main() {
    int n, m, r;
    int result = 0;

    cin >> n >> m >> r;
    Graph graph(n + 1);
    vector<int> item(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }

    for (int i = 0; i < r; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }

    for (int start = 1; start <= n; start++) {
        auto cost = item;
        djikstra(graph, cost, start, m);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += cost[i];
        }

        result = max(result, sum);
    }

    cout << result << '\n';

    return 0;
}