#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> bfs(vector<vector<int>>& home, int r, int c) {
	vector<vector<int>> temp(r, vector<int>(c, 0));
	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (home[i][j] > 0) {
				int spread = home[i][j] / 5;
				int cnt = 0;
				for (int d = 0; d < 4; d++) {
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (ny >= 0 && ny < r && nx >= 0 && nx < c && home[ny][nx] != -1) {
						temp[ny][nx] += spread;
						cnt++;
					}
				}
				temp[i][j] += home[i][j] - spread * cnt;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (home[i][j] == -1)
				temp[i][j] = -1;
		}
	}

	return temp;
}

void clean_air(vector<vector<int>>& home, pair<int, int> up, pair<int, int> down, int r, int c) {
	int uy = up.first;
	int ly = down.first;

	for (int i = uy - 1; i > 0; i--) {
		home[i][0] = home[i - 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		home[0][i] = home[0][i + 1];
	}
	for (int i = 0; i < uy; i++) {
		home[i][c - 1] = home[i + 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		home[uy][i] = home[uy][i - 1];
	}
	home[uy][1] = 0;

	for (int i = ly + 1; i < r - 1; i++) {
		home[i][0] = home[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		home[r - 1][i] = home[r - 1][i + 1];
	}
	for (int i = r - 1; i > ly; i--) {
		home[i][c - 1] = home[i - 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		home[ly][i] = home[ly][i - 1];
	}
	home[ly][1] = 0;

	home[up.first][up.second] = -1;
	home[down.first][down.second] = -1;
}

int main() {
	int r, c, t;
	int result = 0;
	vector<pair<int, int>> air_refresh;
	vector<vector<int>> home;

	cin >> r >> c >> t;
	home.resize(r, vector<int>(c, 0));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> home[i][j];

			if (home[i][j] == -1) {
				air_refresh.push_back({ i,j });
			}
		}
	}

	while (t--) {
		home = bfs(home, r, c);
		clean_air(home, air_refresh[0], air_refresh[1], r, c);
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (home[i][j] > 0) {
				result += home[i][j];
			}
		}
	}

	cout << result;

	return 0;
}