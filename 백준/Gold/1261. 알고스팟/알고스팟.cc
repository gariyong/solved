#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct pos {
	int x;
	int y;
	int broken;

	pos(int x, int y, int broken) : x(x), y(y), broken(broken) {};
};

void bfs(vector<vector<char>>& maze, int n, int m) {
	vector<vector<int>> dist(n, vector<int>(m, 1e9));
	dist[0][0] = 0;

	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };

	deque<pos> q;
	q.push_front(pos(0, 0, 0));

	while (!q.empty()) {
		auto [x, y, broken] = q.front();
		q.pop_front();

		if (broken > dist[y][x]) continue;

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			int nb = broken + (maze[ny][nx] - '0');
			if (nb < dist[ny][nx]) {
				dist[ny][nx] = nb;

				if (maze[ny][nx] == '0') {
					q.push_front(pos(nx, ny, nb));
				}
				else {
					q.push_back(pos(nx, ny, nb));
				}
			}
		}
	}

	cout << dist[n - 1][m - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> m >> n;

	vector<vector<char>> maze(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}

	bfs(maze, n, m);

	return 0;
}