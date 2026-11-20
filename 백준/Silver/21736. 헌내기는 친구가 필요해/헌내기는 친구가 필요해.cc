#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int cnt = 0;
	int** visit;
	char** campus;
	queue <pair<int, int>> q;

	cin >> n >> m;

	campus = new char* [n];
	visit = new int* [n];
	
	for (int i = 0; i < n; i++) {
		campus[i] = new char[m];
		visit[i] = new int[m];

		for (int j = 0; j < m; j++) {
			cin >> campus[i][j];
			visit[i][j] = 0;

			if (campus[i][j] == 'I') {
				q.push({ i,j });
				visit[i][j] = 1;
			}
		}
		cin.ignore();
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		int dy[] = { -1, 1, 0, 0 };
		int dx[] = { 0, 0, -1, 1 };
	
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if (visit[ny][nx] == 0) {
					if (campus[ny][nx] == 'O') {
						q.push({ ny, nx });
					}
					else if (campus[ny][nx] == 'P') {
						cnt++;
						q.push({ ny, nx });
					}
					else if (campus[ny][nx] == 'X') {
					}
					visit[ny][nx] = 1;
				}
			}
		}
	}

	if (cnt == 0) {
		cout << "TT";
	}
	else {
		cout << cnt;
	}

	for (int i = 0; i < n; i++) {
		delete[] visit[i];
		delete[] campus[i];
	}
	delete[] visit;
	delete[] campus;

	return 0;
}