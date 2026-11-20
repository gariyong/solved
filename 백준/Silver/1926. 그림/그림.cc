#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dfs(int n,int m,int**& visit,int**& picture,int y,int x) {
	visit[y][x] = 1;
	int wd[4] = {-1, 1, 0, 0};
	int lr[4] = {0, 0, -1, 1};
	int area = 1;

	for (int i = 0; i < 4; i++) {
		int n_y = y + wd[i];
		int n_x = x + lr[i];

		if (n_y >= 0 && n_y < n && n_x >= 0 && n_x < m && picture[n_y][n_x] == 1 && visit[n_y][n_x] == 0) {
			area += dfs(n, m, visit, picture, n_y, n_x);
		}
	}

	return area;
}

int main() {
	int n, m;
	int cnt = 0;
	int** picture;
	int** visit;
	int area = 0;

	cin >> n >> m;
	visit = new int* [n];
	picture = new int* [n];
	for (int i = 0; i < n; i++) {
		picture[i] = new int[m];
		visit[i] = new int[m];
		for (int j = 0; j < m; j++) {
			visit[i][j] = 0;
			cin >> picture[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (picture[i][j] == 1 && visit[i][j] == 0) {
				int max;
				max = dfs(n, m, visit, picture, i, j);
				if (area < max) {
					area = max;
				}
				cnt++;
			}
		}
	}

	cout << cnt << '\n' << area;

	for (int i = 0; i < n; i++) {
		delete[] visit[i];
		delete[] picture[i];
	}
	delete[] visit;
	delete[] picture;

	return 0;
}