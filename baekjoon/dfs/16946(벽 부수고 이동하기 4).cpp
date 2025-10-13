// 문제 : https://www.acmicpc.net/problem/16946
// 제목 : 벽 부수고 이동하기 4

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int dfs(vector<vector<char>>& map, vector<vector<int>>& group_id, int id, int y, int x, int n, int m) {
	group_id[y][x] = id;
	int cnt = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

		if (map[ny][nx] == '0' && group_id[ny][nx] == -1) {
			cnt += dfs(map, group_id, id, ny, nx, n, m);
		}
	}

	return cnt;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>>map(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	vector<vector<int>>group_id(n, vector<int>(m, -1));
	vector<int>group_size;
	int id = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '0' && group_id[i][j] == -1) {
				int size = dfs(map, group_id, id, i, j, n, m);
				group_size.push_back(size);
				id++;
			}
		}
	}

	vector<vector<int>> result(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '1') {
				set<int> check;
				int sum = 1;

				for (int k = 0; k < 4; k++) {
					int ny = dy[k] + i;
					int nx = dx[k] + j;

					if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

					if (map[ny][nx] == '0' && group_id[ny][nx] != -1) {
						check.insert(group_id[ny][nx]);
					}
				}

				for (int x : check) {
					sum += group_size[x];
				}
				result[i][j] = sum % 10;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j];
		}
		cout << '\n';
	}

	return 0;
}
