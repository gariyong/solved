#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
	int n, m;
	int min = INT_MAX;
	int ans = 0;

	cin >> n >> m;
	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < m; i++) {
		int x, y;

		cin >> x >> y;
	
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		vector<int> distance(n + 1, -1);
		queue<int> q;
		int sum = 0;

		q.push(i);
		distance[i] = 0;

		while (!q.empty()) {
			int user = q.front();
			q.pop();

			for (int j = 0; j < graph[user].size(); j++) {
				int next = graph[user][j];

				if (distance[next] == -1) {
					distance[next] = distance[user] + 1;
					q.push(next);
				}
			}
		}

		for (int j = 1; j <= n; j++) {
			sum += distance[j];
		}

		if (sum < min) {
			min = sum;
			ans = i;
		}
	}
	
	std::cout << ans;

	return 0;
}