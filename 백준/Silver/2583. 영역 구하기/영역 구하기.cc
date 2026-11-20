#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int i, int j, int n, int m, int**& visit, bool**& graph_paper) {
	visit[i][j] = 1;
	int area_size = 1;

	int ud[4] = { -1,1, 0, 0 };
	int lr[4] = { 0, 0, -1, 1 };
	for (int k = 0; k < 4; k++) {
		int ni = i + ud[k];
		int nj = j + lr[k];
		if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
			if (visit[ni][nj] == 0 && graph_paper[ni][nj] == false) {
				area_size += dfs(ni, nj, n, m, visit, graph_paper);
			}
		}
	}

	return area_size;
}

int main() {
	int n, m, k;
	bool** graph_paper;
	int** visit;
	vector <int> v;
	int cnt = 0;

	cin >> n >> m >> k;
	graph_paper = new bool* [n];
	visit = new int* [n];
	for (int i = 0; i < n; i++) {
		graph_paper[i] = new bool[m];
		visit[i] = new int[m];
		for (int j = 0; j < m; j++) {
			graph_paper[i][j] = false;
			visit[i][j] = 0;
		}
	}
	
	for (int i = 0; i < k; i++) {
		int l_x, r_x, l_y, r_y;
		cin >> l_x >> l_y >> r_x >> r_y;
		for (int j = l_y; j < r_y; j++) {
			for (int l = l_x; l < r_x; l++) {
				graph_paper[j][l] = true;
				visit[j][l] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph_paper[i][j] == false && visit[i][j] == 0) {
				v.push_back(dfs(i, j, n, m, visit, graph_paper));
				cnt++;
			}
		}
	}

	sort(v.begin(), v.end());

	cout << cnt << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}

	for (int i = 0; i < n; i++) {
		delete[] visit[i];
		delete[] graph_paper[i];
	}
	delete[] visit;
	delete[] graph_paper;

	return 0;
}