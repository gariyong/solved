#include <iostream>
#include <queue>

using namespace std;

void bfs(int start, int n, int**& node, int**& result) {
	queue<int> q;
	bool* visited = new bool[n] { false };
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next = 0; next < n; next++) {
			if (node[cur][next] == 1 && !visited[next]) {
				visited[next] = true;
				result[start][next] = 1;
				q.push(next);
			}
		}
	}
	delete[] visited;
}

int main() {
	int n;
	cin >> n;

	int** node = new int* [n];
	int** result = new int* [n];

	for (int i = 0; i < n; i++) {
		node[i] = new int[n];
		result[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> node[i][j];
			result[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		bfs(i, n, node, result);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		delete[] node[i];
		delete[] result[i];
	}
	delete[] node;
	delete[] result;

	return 0;
}