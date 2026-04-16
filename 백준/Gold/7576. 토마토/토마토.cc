#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void bfs(int**& farm, int n, int m, int& grow_tomato, int& day) {
	queue <pair<int, int>> q;
	queue <pair<int, int>> next;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (farm[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		day++;
		int t = q.size();

		for (int i = 0; i < t; i++) {
			for (int j = 0; j < 4; j++) {
				int ny = q.front().first + dy[j];
				int nx = q.front().second + dx[j];

				if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
					if (farm[ny][nx] == 0) {
						farm[ny][nx] = 1;
						grow_tomato--;
						next.push({ ny, nx });
					}
				}
			}
			q.pop();
		}

		int nt = next.size();
		for (int i = 0; i < nt; i++) {
			q.push({ next.front().first, next.front().second });
			next.pop();
		}
	}
}

int main() {
	int n, m;
	int grow_tomato = 0;
	int day = 0;
	int** farm;

	cin >> m >> n;
	farm = new int* [n];
	for (int i = 0; i < n; i++) {
		farm[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> farm[i][j];
			if (farm[i][j] == 0) {
				grow_tomato++;
			}
		}
	}

	if (grow_tomato == 0) {
		cout << 0;
	}
	else {
		bfs(farm, n, m, grow_tomato, day);

		if (grow_tomato != 0) {
			cout << -1;
		}
		else {
			cout << day - 1;
		}
	}

	for (int i = 0; i < n; i++) {
		delete[] farm[i];
	}
	delete[] farm;

	return 0;
}