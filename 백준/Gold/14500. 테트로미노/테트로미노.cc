#include <iostream>

using namespace std;

int main() {
	int n, m;
	int max_sum = 0;
	int** paper;
	int tetromino[19][4][2]{
	{{0,0}, {0,1}, {0,2}, {0,3}},
	{{0,0}, {1,0}, {2,0}, {3,0}},
	{{0,0}, {0,1}, {1,0}, {1,1}},
	{{0,0}, {1,0}, {2,0}, {2,1}},
	{{0,1}, {1,1}, {2,1}, {2,0}},
	{{0,0}, {0,1}, {1,1}, {2,1}},
	{{0,0}, {0,1}, {1,0}, {2,0}},
	{{0,0}, {0,1}, {0,2}, {1,2}},
	{{0,0}, {0,1}, {0,2}, {1,0}},
	{{0,0}, {1,0}, {1,1}, {1,2}},
	{{0,2}, {1,0}, {1,1}, {1,2}},
	{{0,0}, {1,0}, {1,1}, {2,1}},
	{{0,1}, {1,1}, {1,0}, {2,0}},
	{{0,1}, {0,2}, {1,0}, {1,1}},
	{{0,0}, {0,1}, {1,1}, {1,2}},
	{{0,0}, {0,1}, {0,2}, {1,1}},
	{{0,1}, {1,0}, {1,1}, {2,1}},
	{{1,0}, {1,1}, {1,2}, {0,1}},
	{{0,0}, {1,0}, {2,0}, {1,1}}
	};

	cin >> n >> m;

	paper = new int* [n];
	for (int i = 0; i < n; i++) {
		paper[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {
				int sum = 0;
				bool flag = true;

				for (int l = 0; l < 4; l++) {
					int y = i + tetromino[k][l][0];
					int x = j + tetromino[k][l][1];

					if (x < 0 || x >= m || y < 0 || y >= n) {
						flag = false;
						break;
					}

					sum += paper[y][x];
				}
				if (flag) {
					max_sum = (int)max(max_sum, sum);
				}
			}
		}
	}

	cout << max_sum;

	for (int i = 0; i < n; i++) {
		delete[] paper[i];
	}
	delete[] paper;

	return 0;
}