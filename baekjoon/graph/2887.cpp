// 문제 : https://www.acmicpc.net/problem/2887
// 제목 : 행성터널
// 알고리즘 : 최소 스패닝 트리(Prim-알고리즘)

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <utility>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Prim 알고리즘으로 MST의 총 비용을 구하는 함수
long long prim(vector<vector<pair<int, int>>>& nodes, int n) {
	vector<int> dist(n, INF);   // 각 노드까지의 최소 거리
	vector<int> visit(n, 0);    // 방문 여부
	long long sum = 0;          // MST 총 비용

	// 우선순위 큐: (비용, 노드) 형태로 최소 비용 간선을 우선 선택
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, 0 });   // 시작 노드(0번) 비용 0으로 시작
	dist[0] = 0;

	while (!q.empty()) {
		auto [cost, cur] = q.top();
		q.pop();

		if (visit[cur]) continue; // 이미 방문한 노드면 스킵

		visit[cur] = 1;   // 방문 처리
		sum += cost;      // MST에 포함된 간선 비용 누적

		// 현재 노드와 인접한 노드들 검사
		for (auto [w, v] : nodes[cur]) {
			// 방문하지 않았고, 더 짧은 경로가 있다면 갱신
			if (!visit[v] && w < dist[v]) {
				dist[v] = w;
				q.push({ w, v });
			}
		}
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// 각 좌표축별로 (좌표값, 노드번호) 저장
	vector<pair<int, int>> x_coords, y_coords, z_coords;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		x_coords.push_back({ x, i });
		y_coords.push_back({ y, i });
		z_coords.push_back({ z, i });
	}

	// 각 축별로 좌표 정렬 (인접 노드끼리 연결하기 위함)
	sort(x_coords.begin(), x_coords.end());
	sort(y_coords.begin(), y_coords.end());
	sort(z_coords.begin(), z_coords.end());

	// 그래프 인접 리스트
	vector<vector<pair<int, int>>> nodes(n);

	// 주어진 좌표축을 기준으로 인접한 두 점을 간선으로 연결하는 함수
	auto create_node = [&](vector<pair<int, int>>& coords) {
		for (int i = 0; i < n - 1; i++) {
			int u = coords[i].second;       // 현재 노드 번호
			int v = coords[i + 1].second;   // 다음 노드 번호
			int cost = abs(coords[i].first - coords[i + 1].first); // 거리(간선 가중치)

			nodes[u].push_back({ cost, v });
			nodes[v].push_back({ cost, u });
		}
		};

	// x, y, z축 기준 각각 인접한 점들끼리 연결
	create_node(x_coords);
	create_node(y_coords);
	create_node(z_coords);

	// Prim 알고리즘을 이용해 최소 스패닝 트리의 총 비용 계산
	long long result = prim(nodes, n);

	cout << result;

	return 0;
}