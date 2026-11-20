#include <iostream>
#include <queue>

using namespace std;

void dfs(int**& visit, int**& farm,int i,int j, int n, int  m) {
	visit[i][j] = 1;
	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };

	for (int k = 0; k < 4; k++) {
		int ny = i + dy[k];
		int nx = j + dx[k];
		if (nx >= 0 && ny >= 0 && nx < m && ny < n && farm[ny][nx] == 1 && visit[ny][nx] == 0) {
			dfs(visit, farm, ny, nx, n, m);
		}
	}
}

int main() {
	int T;

	cin >> T;
	while (T > 0) {
		int n, m, cnt;
		int** farm;
		int** visit;
		int worm = 0;

		cin >> n >> m >> cnt;
		farm = new int* [n];
		visit = new int* [n];
		for (int i = 0; i < n; i++) {
			farm[i] = new int[m];
			visit[i] = new int[m];
			for (int j = 0; j < m; j++) {
				farm[i][j] = 0;
				visit[i][j] = 0;
			}
		}

		for (int i = 0; i < cnt; i++) {
			int x, y;
			cin >> x >> y;
			farm[x][y] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j] == 0 && farm[i][j] == 1) {
					dfs(visit, farm, i, j, n, m);
					worm++;
				}
			}
		}

		cout << worm << '\n';
		T--;
	}

	return 0;
}