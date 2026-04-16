#include <iostream>
#include <queue>

using namespace std;

void dfs(int n, int**& visit, char**& picture, int i, int j) {
	visit[i][j] = 1;
	int wd[4] = { -1, 1, 0, 0 };
	int lr[4] = { 0, 0, -1, 1 };

	for (int k = 0; k < 4; k++) {
		int n_i = i + wd[k];
		int n_j = j + lr[k];

		if (n_i >= 0 && n_i < n && n_j >= 0 && n_j < n && visit[n_i][n_j] == 0) {
			if (picture[i][j] == picture[n_i][n_j]) {
				dfs(n, visit, picture, n_i, n_j);
			}
		}
	}
}

int main() {
	int n;
	int cnt_1 = 0;
	int cnt_2 = 0;
	int** visit;
	char** picture;

	cin >> n;
	visit = new int* [n];
	picture = new char* [n];
	for (int i = 0; i < n; i++) {
		visit[i] = new int[n];
		picture[i] = new char[n];
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
			cin >> picture[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0) {
				dfs(n, visit, picture, i, j);
				cnt_1++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] == 'G') {
				picture[i][j] = 'R';
			}
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0) {
				dfs(n, visit, picture, i, j);
				cnt_2++;
			}
		}
	}

	cout << cnt_1 << ' ' << cnt_2;

	return 0;
}