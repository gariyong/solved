#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <limits>
#include <functional>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<int>> dijkstra(int n, int m, int t, vector<vector<int>>& map, int sy, int sx) {
	vector<vector<int>> distance(n, vector<int>(m, INF));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;

	distance[sy][sx] = 0;
	q.push({0, sy, sx});

	while (!q.empty()) {
		int ncost;
		int dy[] = { -1, 1, 0, 0 };
		int dx[] = { 0, 0, -1, 1 };

		auto [cost, y, x] = q.top();
		q.pop();

		if (distance[y][x] < cost) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
				continue;
			}

			if (abs(map[y][x] - map[ny][nx]) > t) {
				continue;
			}

			if (map[y][x] >= map[ny][nx]) {
				ncost = cost + 1;
			}
			else {
				ncost = cost + (int)pow(abs(map[y][x] - map[ny][nx]), 2);
			}

			if (ncost < distance[ny][nx]) {
				distance[ny][nx] = ncost;
				q.push({ ncost, ny, nx });
			}
		}
	}

	return distance;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, t, d;
	int result;
	string row;
	
	cin >> n >> m >> t >> d;
	vector<vector<int>> map(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		cin >> row;
		for (int j = 0; j < m; j++) {
			if (row[j] >= 'A' && row[j] <= 'Z')
				map[i][j] = row[j] - 'A';
			else
				map[i][j] = row[j] - 'a' + 26;
		}
	}

	auto go_time = dijkstra(n, m, t, map, 0, 0);
	result = map[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (go_time[i][j] == INF) {
				continue;
			}

			auto back_time = dijkstra(n, m, t, map, i, j);
			
			if (back_time[0][0] == INF) {
				continue;
			}

			if (go_time[i][j] + back_time[0][0] <= d) {
				result = max(result, map[i][j]);
			}
		}
	}

	cout << result;

	return 0;
}