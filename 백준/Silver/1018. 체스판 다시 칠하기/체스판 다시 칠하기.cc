#include <iostream>

using namespace std;

char W_board[8][8] =
{
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'
};

char B_board[8][8] =
{
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'
};

int cmp_W(int x, int y, char**& chess_board) {
	int result = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess_board[x + i][y + j] != W_board[i][j]) {
				result++;
			}
		}
	}

	return result;
}

int cmp_B(int x, int y, char**& chess_board) {
	int result = 0;

	for(int i = 0; i<8; i++){
		for (int j = 0; j < 8; j++) {
			if (chess_board[x + i][y + j] != B_board[i][j]) {
				result++;
			}
		}
	}

	return result;
}

int main()
{
	int n, m;
	int answer = 64;
	char** chess_board;

	cin >> n >> m;

	chess_board = new char* [n];
	for (int i = 0; i < n; i++) {
		chess_board[i] = new char[m];
		for (int j = 0; j < m; j++) {
			cin >> chess_board[i][j];
		}
	}

	int cnt_white = 0;
	int cnt_black = 0;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			cnt_white = cmp_W(i, j, chess_board);
			cnt_black = cmp_B(i, j, chess_board);
			if (cnt_white < cnt_black) {
				if (cnt_white < answer) {
					answer = cnt_white;
				}
			}
			else {
				if (cnt_black < answer)
					answer = cnt_black;
			}
		}
	}

	cout << answer;

	return 0;
}