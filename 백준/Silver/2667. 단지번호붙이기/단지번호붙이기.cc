#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(char**& apt, int**& visit, int i, int j, int n) {
	visit[i][j] = 1;
	int cnt = 1;
	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };

	for (int k = 0; k < 4; k++) {
		int ny = i + dy[k];
		int nx = j + dx[k];

		if (ny >= 0 && ny < n && nx >= 0 && nx < n && apt[ny][nx] == '1' && visit[ny][nx] == 0) {
			 cnt += dfs(apt, visit, ny, nx, n);
		}
	}

	return cnt;
}

int main() {
	int n;
	char** apt;
	int** visit;
	vector <int> v;

	cin >> n;
	apt = new char* [n];
	visit = new int* [n];
	for (int i = 0; i < n; i++) {
		apt[i] = new char[n];
		visit[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> apt[i][j];
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0 && apt[i][j] == '1') {
				v.push_back(dfs(apt, visit, i, j, n));
			}
		}
	}

	sort(v.begin(), v.end());

	int len = (int)v.size();
	cout << len << '\n';
	for (int i = 0; i < len; i++) {
		cout << v[i] << '\n';
	}
	
	for (int i = 0; i < n; i++) {
		delete[] apt[i];
		delete[] visit[i];
	}
	delete[] apt;
	delete[] visit;

	return 0;
}