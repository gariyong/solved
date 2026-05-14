#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int bfs(vector<string>& storage, char target, int n, int m) {
	queue<pair<int, int>> q;
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		if (storage[i][0] == target) {
			visit[i][0] = true;
			storage[i][0] = '.';
			cnt++;
		}else if(storage[i][0] == '.') {
			visit[i][0] = true;
			q.push({ i, 0 });
		}

		if (storage[i][m - 1] == target) {
			visit[i][m - 1] = true;
			storage[i][m - 1] = '.';
			cnt++;
		}
		else if (storage[i][m - 1] == '.') {
			visit[i][m - 1] = true;
			q.push({ i, m - 1 });
		}
	}

	for(int i = 0; i < m; i++) {
		if (storage[0][i] == target) {
			visit[0][i] = true;
			storage[0][i] = '.';
			cnt++;
		}else if(storage[0][i] == '.') {
			visit[0][i] = true;
			q.push({ 0, i });
		}
		if (storage[n - 1][i] == target) {
			visit[n - 1][i] = true;
			storage[n - 1][i] = '.';
			cnt++;
		}
		else if (storage[n - 1][i] == '.') {
			visit[n - 1][i] = true;
			q.push({ n - 1, i });
		}
	}

	while(!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visit[ny][nx]) continue;

			if (storage[ny][nx] == target) {
				visit[ny][nx] = true;
				storage[ny][nx] = '.';
				cnt++;
			}
			else if (storage[ny][nx] == '.') {
				visit[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}

	return cnt;
}

int solution(vector<string> storage, vector<string> requests) {
	int n = storage.size();
	int m = storage[0].size();
	int	result = n * m;

	for (auto cur : requests) {
		char target = cur[0];

		if (cur.length() == 2) {
			for(int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (storage[i][j] == target) {
						storage[i][j] = '.';
						result--;
					}
				}
			}

			continue;
		}

		result -= bfs(storage, target, n, m);
	}

	return result;
}