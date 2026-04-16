#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>
#include <functional>

using namespace std;

const int INF = numeric_limits<int>::max();

int dijkstra(vector<vector<pair<int, int>>>& graph, int start, int end) {
    vector<int> distance(graph.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    distance[start] = 0;

    q.push({ distance[start], start });

    while (!q.empty()) {
        int cur = q.top().second;
        int cur_dis = q.top().first;
        q.pop();

        if (cur_dis > distance[cur]) continue;

        int len = (int)graph[cur].size();
        for (int i = 0; i < len; i++) {
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second;

            if (distance[next] > cost + cur_dis) {
                distance[next] = cost + cur_dis;
                q.push({ distance[next], next });
            }
        }
    }

    return distance[end];
}

int main() {
    int n, e, v1, v2;

    cin >> n >> e;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    cin >> v1 >> v2;

    int a = dijkstra(graph, 1, v1);
    int b = dijkstra(graph, v1, v2);
    int c = dijkstra(graph, v2, n);

    int x = dijkstra(graph, 1, v2);
    int y = dijkstra(graph, v2, v1);
    int z = dijkstra(graph, v1, n);

    long long path1 = (a == INF || b == INF || c == INF) ? INF : 1LL * a + b + c;
    long long path2 = (x == INF || y == INF || z == INF) ? INF : 1LL * x + y + z;

    if (path1 == INF && path2 == INF) {
        cout << -1;
    }
    else {
        cout << min(path1, path2);
    }

    return 0;
}