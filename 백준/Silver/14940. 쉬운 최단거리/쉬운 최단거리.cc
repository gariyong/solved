#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, m;
	int** map;
	int** visit;
	queue <pair<int, int>> q;

	cin >> n >> m;

	map = new int* [n];
	visit = new int* [n];

	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		visit[i] = new int[m];

		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			visit[i][j] = 0;

			if (map[i][j] == 2) {
				q.push({ i, j });
				map[i][j] = 0;
				visit[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		
		int dy[] = { -1, 1, 0, 0 };
		int dx[] = { 0, 0, -1, 1 };
		
		for (int k = 0; k < 4; k++) {
			int ny = dy[k] + i;
			int nx = dx[k] + j;

			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if (visit[ny][nx] == 0 && map[ny][nx] == 1) {
					q.push({ ny, nx });
					visit[ny][nx] = 1;
					map[ny][nx] = map[i][j] + 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				cout << -1 << ' ';
			}
			else {
				cout << map[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		delete[] map[i];
		delete[] visit[i];
	}
	delete[] map;
	delete[] visit;

	return 0;
}