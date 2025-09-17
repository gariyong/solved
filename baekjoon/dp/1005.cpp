// 문제 : https://www.acmicpc.net/problem/1005
// 제목 : ACM Craft

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> craft_time(n + 1);
		vector<vector<int>> build(n + 1);
		vector<int> indegree(n + 1, 0);

		for (int i = 1; i <= n; i++) {
			cin >> craft_time[i];
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;

			build[x].push_back(y);
			indegree[y]++;
		}

		int w;
		cin >> w;

		vector<int> dp(n + 1, -1);
		queue<int> q;

		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				dp[i] = craft_time[i];
			}
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int next : build[cur]) {
				indegree[next]--;
				dp[next] = max(dp[next], dp[cur] + craft_time[next]);

				if (indegree[next] == 0) {
					q.push(next);
				}
			}
		}

		cout << dp[w] << "\n";
	}

	return 0;
}