// 문제: https://www.acmicpc.net/problem/14502
// 제목: 연구소

// bfs를 사용하긴했지만 백트래킹으로 벽을 세우는 부분이 중요하다고 생각해서 백트래킹으로 분류, 탐색은 dfs를 사용해도 되기 때문에
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(vector<vector<int>>& lab, vector<pair<int, int>>& virus, int n, int m) {
	queue<pair<int, int>> q;
	vector<vector<int>> copy_lab = lab;
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };
	int safe_area = 0;

	for (auto& v : virus) {
		q.push(v);
	}

	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n && copy_lab[ny][nx] == 0) {
				copy_lab[ny][nx] = 2;
				q.push({ ny, nx });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copy_lab[i][j] == 0) {
				safe_area++;
			}
		}
	}

	return safe_area;
}

void place_walls(int cnt, vector<vector<int>>& lab, vector<pair<int, int>>& virus, int n, int m, int& max) {
	if (cnt == 3) {
		max = std::max(max, bfs(lab, virus, n, m));
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) {
				lab[i][j] = 1;
				place_walls(cnt + 1, lab, virus, n, m, max);
				lab[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	int result = -1;

	cin >> n >> m;
	vector<vector<int>> lab(n, vector<int>(m));
	vector<pair<int, int>> virus;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];

			if (lab[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	place_walls(0, lab, virus, n, m, result);

	cout << result;

	return 0;
}
