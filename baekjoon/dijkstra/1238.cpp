// 문제: https://www.acmicpc.net/problem/1238
// 제목: 파티

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& distance, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    distance[start] = 0;
    q.push({ 0, start });

    while (!q.empty()) {
        auto [cost, cur] = q.top(); q.pop();
        if (cost > distance[cur]) {
            continue;
        }

        for (auto& [next, w] : graph[cur]) {
            int next_cost = cost + w;
            if (next_cost < distance[next]) {
                distance[next] = next_cost;
                q.push({ next_cost, next });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;

    // 인접 행렬 -> 인접 리스트로 변경 + 역방향 그래프 추가
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<vector<pair<int, int>>> reverse_graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        reverse_graph[v].emplace_back(u, w);
    }

    vector<int> to_x(n + 1, INF);
    vector<int> from_x(n + 1, INF);

    // 다익스트라 실행을 n번 실행 -> 2번 실행으로 수정
    dijkstra(reverse_graph, to_x, x);
    dijkstra(graph, from_x, x);

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        if (to_x[i] != INF && from_x[i] != INF)
            result = max(result, to_x[i] + from_x[i]);
    }

    cout << result;

    return 0;
}