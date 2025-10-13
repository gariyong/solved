// 문제 : https://www.acmicpc.net/problem/1719
// 제목 : 택배

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

const int INF = 1e9;

// 다익스트라 알고리즘
void dijkstra(vector<vector<pair<int, int>>>& nodes, vector<vector<int>>& path, int start, int n) {
	vector<int> dist(n + 1, INF); // 거리 배열 초기화 
	dist[start] = 0; // 시작점에서부터 시작점까지의 거리는 0

	// [비용, 현재노드]저장하는 우선순위 큐(최소 힙)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>	q;
	q.push({ 0, start }); // 시작 노드를 큐에 넣음

	while (!q.empty()) {
		auto [cost, cur] = q.top(); // 현재까지의 비용과 노드
		q.pop();

		// 이미 더 짧은 경로가 존재한다면 스킵
		if (cost > dist[cur]) continue;

		// 현재 노드에서 이동 가능한 모든 인접 노드 탐색
		for (auto [next, n_cost] : nodes[cur]) {

			// 현재 노드를 거쳐서 가는 비용이 더 작으면 갱신
			if (dist[cur] + n_cost < dist[next]) {
				dist[next] = dist[cur] + n_cost;
				q.push({ dist[next], next });

				// 시작점에서 바로 인접한 점이면 가장 먼저 접해야할 집하장으로 설정
				if (cur == start) {
					path[start][next] = next;
				}
				// 그렇지 않으면, 현재 노드로 가는 첫 번째 집하장을 그대로 이어받음
				else {
					path[start][next] = path[start][cur];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m; // n : 노드 수, m : 집하장 수

	vector<vector<pair<int, int>>>nodes(n + 1);
	for (int i = 0; i < m; i++) {
		// u, v : 노드, w : 가중치
		int u, v, w;
		cin >> u >> v >> w;

		// 양방향 그래프
		nodes[u].push_back({ v, w });
		nodes[v].push_back({ u, w });
	}

	// path[i][j] : i에서 j로 갈 때 첫 번째로 거쳐야 할 노드
	vector<vector<int>> path(n + 1, vector<int>(n + 1));

	// 각 노드를 시작점으로해서 다익스트라 수행
	for (int start = 1; start <= n; start++) {
		dijkstra(nodes, path, start, n);
	}

	// 결과 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << '-';
			}
			else {
				cout << path[i][j];
			}

			if (j < n) {
				cout << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
