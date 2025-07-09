// 문제: https://www.acmicpc.net/problem/2206
// 제목: 벽 부수고 이동하기

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> bfs(vector<vector<char>>& graph, vector<vector<int>>& visited, int n, int m) {
	queue<pair<pair<int, int>, int>> q;
	vector<vector<int>> distance(n + 1, vector<int>(m + 1, -1));
	vector<vector<int>> visited_break(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> distance_break(n + 1, vector<int>(m + 1, -1));
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };

	q.push({ {1,1}, 0 });
	distance[1][1] = 1;
	visited[1][1] = 1;

	while (!q.empty()) {
		auto [cur, wall_break] = q.front();
		q.pop();

		int x = cur.second, y = cur.first;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > m || ny < 1 || ny > n) {
				continue;
			}

			if (wall_break == 0) {
				if (visited[ny][nx] == 1) {
					continue;
				}

				if (graph[ny][nx] == '0') {
					visited[ny][nx] = 1;
					q.push({ {ny, nx}, wall_break });
					distance[ny][nx] = distance[y][x] + 1;
				}
				else if (graph[ny][nx] == '1' && wall_break == 0) {
					visited[ny][nx] = 1;
					q.push({ {ny, nx}, 1 });
					distance_break[ny][nx] = distance[y][x] + 1;
				}
			}

			if (wall_break == 1) {
				if (visited_break[ny][nx] == 1) {
					continue;
				}

				if (graph[ny][nx] == '0') {
					visited_break[ny][nx] = 1;
					q.push({ {ny, nx}, wall_break });
					distance_break[ny][nx] = distance_break[y][x] + 1;
				}
				else if (graph[ny][nx] == '1' && wall_break == 0) {
					visited_break[ny][nx] = 1;
					q.push({ {ny, nx}, 1 });
					distance_break[ny][nx] = distance_break[y][x] + 1;
				}
			}
		}
	}

	if (distance[n][m] == -1) {
		return distance_break;
	}
	else if (distance_break[n][m] == -1) {
		return distance;
	}
	else {
		return (distance[n][m] < distance_break[n][m]) ? distance : distance_break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;

	cin >> n >> m;
	cin.ignore();

	vector<vector<char>> graph(n + 1, vector<char>(m + 1));
	vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
		cin.ignore();
	}

	auto result = bfs(graph, visited, n, m);

	cout << result[n][m];

	return 0;
}