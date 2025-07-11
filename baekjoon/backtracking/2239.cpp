// 문제: https://www.acmicpc.net/problem/2239
// 제목: 스도쿠

#include <iostream>
#include <vector>

using namespace std;

bool solved = false;

void backtracking(vector<vector<char>>& sudoku, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& box, int i, int j) {
	if (solved) {
		return;
	}

	if (i == 9) {
		for (const auto& r : sudoku) {
			for (char c : r) {
				cout << c;
			}
			cout << '\n';
		}
		solved = true;

		return;
	}

	if (j == 9) {
		backtracking(sudoku, row, col, box, i + 1, 0);

		return;
	}

	if (sudoku[i][j] != '0') {
		backtracking(sudoku, row, col, box, i, j + 1);

		return;
	}

	for (int num = 0; num < 9; num++) {
		if (!row[i][num] && !col[j][num] && !box[(i / 3) * 3 + (j / 3)][num]) {
			sudoku[i][j] = '1' + num;
			row[i][num] = true;
			col[j][num] = true;
			box[(i / 3) * 3 + (j / 3)][num] = true;

			backtracking(sudoku, row, col, box, i, j + 1);

			if (!solved) {
				sudoku[i][j] = '0';
				row[i][num] = false;
				col[j][num] = false;
				box[(i / 3) * 3 + (j / 3)][num] = false;
			}
		}
	}
}

int main() {
	vector<vector<char>> sudoku(9, vector<char>(9));
	vector<vector<bool>> row(9, vector<bool>(9, false));
	vector<vector<bool>> col(9, vector<bool>(9, false));
	vector<vector<bool>> box(9, vector<bool>(9, false));

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];

			if (sudoku[i][j] != '0') {
				int num = sudoku[i][j] - '1';
				row[i][num] = true;
				col[j][num] = true;
				box[(i / 3) * 3 + (j / 3)][num] = true;
			}
		}
	}

	backtracking(sudoku, row, col, box, 0, 0);

	return 0;
}