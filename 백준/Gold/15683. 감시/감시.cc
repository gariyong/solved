#include <iostream>
#include <vector>

using namespace std;

struct pos {
	int x, y, type;
};

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<vector<int>> watch_dir = {
	{},
	{ 0 },
	{ 0, 2 },
	{ 0, 1 },
	{ 0, 1, 2 },
	{ 0, 1, 2, 3 }
};

void watch(vector<vector<char>>& room, int x, int y, int dir) {
	int n = room.size();
	int m = room[0].size();

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	while (nx >= 0 && nx < n && ny >= 0 && ny < m && room[nx][ny] != '6') {
		if (room[nx][ny] == '0') room[nx][ny] = '#';
		nx += dx[dir];
		ny += dy[dir];
	}
}

void dfs(int idx, vector<vector<char>> room, vector<pos>& cctv, int& result) {
	if (idx == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < room.size(); i++) {
			for (int j = 0; j < room[i].size(); j++) {
				if (room[i][j] == '0') cnt++;
			}
		}
		result = min(result, cnt);
		return;
	}

	pos& c = cctv[idx];
	for (int d = 0; d < 4; d++) {
		vector<vector<char>> copy = room;
		for (int offset : watch_dir[c.type]) {
			watch(copy, c.x, c.y, (d + offset) % 4);
		}
		dfs(idx + 1, copy, cctv, result);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<char>> room(n, vector<char>(m));
	vector<pos> cctv;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			room[i][j] = c;

			if (c >= '1' && c <= '5') {
				cctv.push_back({ i, j, c - '0' });
			}
		}
	}

	int result = 64;
	dfs(0, room, cctv, result);
    
	cout << result;

	return 0;
}