// 문제 : https://www.acmicpc.net/problem/2447
// 제목 : 별 찍기 - 10

#include <iostream>
#include <vector>

using namespace std;

void divide_star(vector<vector<char>>& board, int y, int x, int size) {
    if (size == 1) {
        board[y][x] = '*';
        return;
    }

    int div = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                for (int a = y + i * div; a < y + (i + 1) * div; a++) {
                    for (int b = x + j * div; b < x + (j + 1) * div; b++) {
                        board[a][b] = ' ';
                    }
                }
            }
            else {
                divide_star(board, y + i * div, x + j * div, div);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, ' '));

    divide_star(board, 0, 0, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}
