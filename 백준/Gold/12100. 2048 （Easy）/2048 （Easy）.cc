#include <iostream>
#include <vector>

using namespace std;

void move_left(vector<vector<int>>& board, int n) {
	for (int i = 0; i < n; i++) {
		vector<int> line;

		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0)
				line.push_back(board[i][j]);
		}

		vector<int> merged;
		for (int j = 0; j < line.size(); j++) {
			if (j + 1 < line.size() && line[j] == line[j + 1]) {
				merged.push_back(line[j] * 2);
				j++;
			}
			else {
				merged.push_back(line[j]);
			}
		}

		for (int j = 0; j < n; j++) {
			if (j < merged.size())
				board[i][j] = merged[j];
			else
				board[i][j] = 0;
		}
	}
}

void rotate_left(vector<vector<int>>& board, int n) {
	vector<vector<int>> new_board(n, vector<int>(n));

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			new_board[n - 1 - x][y] = board[y][x];
		}
	}

	board = new_board;
}

void rotate_right(vector<vector<int>>& board, int n) {
	vector<vector<int>> new_board(n, vector<int>(n));

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			new_board[x][n - 1 - y] = board[y][x];
		}
	}

	board = new_board;
}

void rotate_board(vector<vector<int>>& board, int dir, int n) {
	switch (dir) {
	case 0: break;
	case 1: for (int i = 0; i < 2; i++) rotate_right(board, n); break;
	case 2: rotate_right(board, n); break;
	case 3: rotate_left(board, n); break;
	}
}

void dfs(vector<vector<int>>& board, int n, int cnt, int& result) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j ++) {
				result = max(result, board[i][j]);
			}
		}

		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		vector<vector<int>> temp = board;

		rotate_board(board, dir, n);
		move_left(board, n);
		dfs(board, n, cnt + 1, result);

		board = temp;
	}
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int result = -1;
	dfs(board, n, 0, result);

	cout << result;

	return 0;
}