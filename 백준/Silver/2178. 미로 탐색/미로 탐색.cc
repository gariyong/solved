#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void bfs(vector<vector<char>>& maze, int n, int m) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {1, 1}, 1 });

	vector<vector<bool>> visit(n + 1, vector<bool>(m + 1, false));
	visit[1][1] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		int y = cur.first.first;
		int x = cur.first.second;
		int dist = cur.second;

		if (y == n && x == m) {
			cout << dist;
			
			return;
		}

		for(int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			
			if (ny < 1 || ny > n || nx < 1 || nx > m) continue;
			if (maze[ny][nx] == '0') continue;
			if (visit[ny][nx]) continue;
			
			visit[ny][nx] = true;
			q.push({ {ny, nx}, dist + 1 });
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> maze(n + 1, vector<char>(m + 1));
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> maze[i][j];
		}
	}

	bfs(maze, n, m);

	return 0;
}