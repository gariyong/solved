// 문제 : https://www.acmicpc.net/problem/2638
// 제목 : 치즈

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void bfs(vector<vector<int>>& graph, int n, int m, int sy, int sx) {
	queue<pair<int, int>> q;
	q.push({ sy,sx, });
	graph[sy][sx] = 2;

	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
				continue;
			}
			if (graph[ny][nx] == 0) {
				graph[ny][nx] = 2;
				q.push({ ny, nx });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	int cheese = 0;
	int hour = 0;

	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(m));
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				cheese++;
				q.push({ i, j });
			}
		}
	}
	vector<vector<int>> visited = graph;

	bfs(graph, n, m, 0, 0);

	while (cheese > 0) {
		int size = (int)q.size();
		queue<pair<int, int>> area;

		while (size--) {
			int cnt = 0;
			auto [y, x] = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
					continue;
				}

				if (graph[ny][nx] == 2) {
					cnt++;
				}
			}

			if (cnt >= 2) {
				visited[y][x] = 0;
				area.push({ y, x });
				cheese--;
			}
			else {
				q.push({ y, x });
			}
		}

		graph = visited;
		hour++;

		int area_size = (int)area.size();
		for (int i = 0; i < area_size; i++) {
			auto [y, x] = area.front();
			area.pop();
			if (graph[y][x] == 2) {
				continue;
			}
			bfs(graph, n, m, y, x);
		}
	}

	cout << hour;

	return 0;
}
