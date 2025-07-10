// 문제: https://www.acmicpc.net/problem/1197
// 제목: 최소 스패닝 트리

// 프림 알고리즘 사용
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int v, e;
	cin >> v >> e;

	vector<vector<pair<int, int>>> graph(v + 1);
	vector<bool> visited(v + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;

		graph[a].push_back({ w, b });
		graph[b].push_back({ w, a });
	}

	pq.push({ 0, 1 });
	int result = 0;

	while (!pq.empty()) {
		auto [cost, u] = pq.top(); pq.pop();

		if (visited[u]) {
			continue;
		}

		visited[u] = true;
		result += cost;

		for (auto [w, to] : graph[u]) {
			if (!visited[to]) {
				pq.push({ w, to });
			}
		}
	}

	cout << result;

	return 0;
}