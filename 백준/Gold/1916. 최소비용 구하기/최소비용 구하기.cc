#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

using Edge = pair<int, int>; // (목적지, 가중치)
using Graph = vector<vector<Edge>>;
const int INF = numeric_limits<int>::max();

void dijkstra(int start, const Graph& graph, vector<int>& dist) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cur_dist > dist[cur]) continue;

        for (const auto& edge : graph[cur]) {
            int next = edge.first;
            int cost = edge.second;
            if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
                pq.emplace(dist[next], next);
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph graph(n + 1);
    vector<int> dist(n + 1, INF);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start, graph, dist);

	cout << dist[end] << endl;

    return 0;
}