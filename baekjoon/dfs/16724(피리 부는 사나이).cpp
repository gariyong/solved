// 문제 : https://www.acmicpc.net/problem/16724
// 제목 : 피리 부는 사나이

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dfs(vector<string>& map, vector<vector<int>>& visit, int x, int y) {
	if (visit[y][x] == 1) {
		return 1;
	}
	if (visit[y][x] == 2) {
		return 0;
	}

	visit[y][x] = 1;
	int ny = y;
	int nx = x;

	switch (map[y][x]) {
	case 'U':
		ny--;
		break;
	case 'D':
		ny++;
		break;
	case 'L':
		nx--;
		break;
	case 'R':
		nx++;
		break;
	}

	int add = dfs(map, visit, nx, ny);
	visit[y][x] = 2;

	return add;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string>map(n);
	vector<vector<int>>visit(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == -1) cnt += dfs(map, visit, j, i);
		}
	}

	cout << cnt;

	return 0;
}
