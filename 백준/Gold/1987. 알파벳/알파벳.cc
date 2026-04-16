#include <iostream>
#include <algorithm>

using namespace std;

char board[20][20];

void dfs(int y, int x, bool* visit, int& sum, int cnt, int r, int c) {
	sum = max(cnt, sum);

	 int dy[] = { -1, 1, 0, 0 };
	 int dx[] = { 0, 0, -1, 1 };

	 for (int i = 0; i < 4; i++) {
		 int ny = y + dy[i];
		 int nx = x + dx[i];

		 if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
			 continue;
		 }

		 if (!visit[board[ny][nx] - 'A']) {
			 visit[board[ny][nx] - 'A'] = true;
			 dfs(ny, nx, visit, sum, cnt + 1, r, c);
			 visit[board[ny][nx] - 'A'] = false;
		 }
	 }
}

int main() {
	int r, c;
	int sum = 0, cnt = 0;
	bool visit[26] = { 0 };

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	visit[board[0][0] - 'A'] = true;
	dfs(0, 0, visit, sum, 1, r, c);

	cout << sum;

	return 0;
}