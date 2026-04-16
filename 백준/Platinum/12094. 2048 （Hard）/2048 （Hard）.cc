#include <iostream>
#include <vector>

using namespace std;

int board[20][20];
int n;
int result = -1;

int get_max() {
	int x = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x = max(x, board[i][j]);
		}
	}

	return x;
}

bool move_board(int dir) {
	bool moved = false;
	bool merged[20][20] = { false, };

	if (dir == 0) {	// left
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (board[i][j] == 0) continue;

				int temp = j;
				while (temp > 0 && board[i][temp - 1] == 0) {
					board[i][temp - 1] = board[i][temp];
					board[i][temp] = 0;
					temp--;
					moved = true;
				}

				if (temp > 0 && board[i][temp - 1] == board[i][temp] && !merged[i][temp - 1]) {
					board[i][temp - 1] *= 2;
					board[i][temp] = 0;
					merged[i][temp - 1] = true;
					moved = true;
				}
			}
		}
	}
	else if (dir == 1) {	// right
		for (int i = 0; i < n; i++) {
			for (int j = n - 2; j >= 0; j--) {
				if (board[i][j] == 0) continue;

				int temp = j;
				while (temp < n - 1 && board[i][temp + 1] == 0) {
					board[i][temp + 1] = board[i][temp];
					board[i][temp] = 0;
					temp++;
					moved = true;
				}

				if (temp < n - 1 && board[i][temp + 1] == board[i][temp] && !merged[i][temp + 1]) {
					board[i][temp + 1] *= 2;
					board[i][temp] = 0;
					merged[i][temp + 1] = true;
					moved = true;
				}
			}
		}
	}
	else if (dir == 2) {	// up
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (board[j][i] == 0) continue;

				int temp = j;
				while (temp > 0 && board[temp - 1][i] == 0) {
					board[temp - 1][i] = board[temp][i];
					board[temp][i] = 0;
					temp--;
					moved = true;
				}

				if (temp > 0 && board[temp - 1][i] == board[temp][i] && !merged[temp - 1][i]) {
					board[temp - 1][i] *= 2;
					board[temp][i] = 0;
					merged[temp - 1][i] = true;
					moved = true;
				}
			}
		}
	}
	else if (dir == 3) {	// down
		for (int i = 0; i < n; i++) {
			for (int j = n - 2; j >= 0; j--) {
				if (board[j][i] == 0) continue;

				int temp = j;
				while (temp < n - 1 && board[temp + 1][i] == 0) {
					board[temp + 1][i] = board[temp][i];
					board[temp][i] = 0;
					temp++;
					moved = true;
				}

				if (temp < n - 1 && board[temp + 1][i] == board[temp][i] && !merged[temp + 1][i]) {
					board[temp + 1][i] *= 2;
					board[temp][i] = 0;
					merged[temp + 1][i] = true;
					moved = true;
				}
			}
		}
	}
	return moved;
}

void dfs(int cnt) {
	int cur_max = get_max();

	if (cur_max > result) result = cur_max;
	if (cnt == 10) return;
	if ((cur_max << (10 - cnt)) <= result) return;

	int backup_board[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			backup_board[i][j] = board[i][j];
		}
	}

	for (int dir = 0; dir < 4; dir++) {
		if (move_board(dir)) {
			dfs(cnt + 1);

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					board[i][j] = backup_board[i][j];
				}
			}
		}
	}
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0);
	cout << (result == -1 ? get_max() : result);

	return 0;
}