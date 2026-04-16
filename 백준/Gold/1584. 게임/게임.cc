	#include <iostream>
	#include <queue>
	#include <limits>
	#include <functional>
	#include <algorithm>

	using namespace std;

	const int INF = numeric_limits<int>::max();
	int graph[501][501] = { 0 };


	vector<vector<int>> dijkstra(int sy, int sx) {
		vector<vector<int>> life(501, vector<int>(501, INF));
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;

		q.push({ 0, {sy, sx} });
		life[sy][sx] = 0;

		while (!q.empty()) {
			auto [cost, cur] = q.top();
			q.pop();

			int y = cur.first;
			int x = cur.second;

			if (life[y][x] < cost) {
				continue;
			}

			int dy[] = { -1, 1, 0, 0 };
			int dx[] = { 0, 0, -1, 1 };

			for(int i = 0; i < 4; i++){
				int ny = dy[i] + y;
				int nx = dx[i] + x;

				if (ny > 500 || nx > 500 || nx < 0 || ny < 0) {
					continue;
				}

				if (graph[ny][nx] == 0) {
					if (life[ny][nx] > cost) {
						life[ny][nx] = cost;
						q.push({ cost, { ny, nx } });
					}
				}

				if (graph[ny][nx] == 1) {
					int ncost = cost + 1;

					if (life[ny][nx] > ncost) {
						life[ny][nx] = ncost;
						q.push({ ncost, {ny, nx} });
					}
				}

				if (graph[ny][nx] == 2) {
					continue;
				}
			}
		}

		return life;
	}


	int main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m;

		cin >> n;
	
		for (int i = 0; i < n; i++) {
			int x1, y1, x2, y2;

			cin >> x1 >> y1 >> x2 >> y2;

			if (y1 > y2) {
				int temp = y1;
				y1 = y2;
				y2 = temp;
			}

			if (x1 > x2) {
				int temp = x1;
				x1 = x2;
				x2 = temp;
			}

			for (int ny = y1; ny <= y2; ny++) {
				for (int nx = x1; nx <= x2; nx++) {
					graph[ny][nx] = 1;
				}
			}
		}

		cin >> m;

		for (int i = 0; i < m; i++) {
			int x1, y1, x2, y2;

			cin >> x1 >> y1 >> x2 >> y2;

			if (y1 > y2) {
				int temp = y1;
				y1 = y2;
				y2 = temp;
			}

			if (x1 > x2) {
				int temp = x1;
				x1 = x2;
				x2 = temp;
			}

			for (int ny = y1; ny <= y2; ny++) {
				for (int nx = x1; nx <= x2; nx++) {
					graph[ny][nx] = 2;
				}
			}
		}

		auto result = dijkstra(0, 0);

		cout << (result[500][500] == INF ? -1 : result[500][500]);

		return 0;
	}