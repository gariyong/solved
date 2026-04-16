#include <iostream>
#include <queue>
#include <limits>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();
int main() {
	int n, k;
	int cnt = 0;
	vector<int> dot(100001, INF);
	queue <int> q;

	cin >> n >> k;

	dot[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int next;
		int cost;

		for (int i = 0; i < 3; i++) {
			if (i == 0 && cur + 1 <= 100000) {
				next = cur + 1;
			}
			else if (i == 1 && cur - 1 >= 0) {
				next = cur - 1;
			}
			else if (i == 2 && cur * 2 <= 100000) {
				next = cur * 2;
			}
			else {
				continue;
			}

			cost = dot[cur] + 1;

			if (dot[next] >= cost) {
				dot[next] = cost;
				q.push(next);
			}

			if (next == k) {
				if (cost == dot[k]) {
					cnt++;
				}
				else if (dot[k] == INF || cost < dot[k]) {
					dot[k] = cost;
					cnt = 1;
				}
			}
		}
	}

	cout << dot[k] << '\n';
	if (n == k) {
		cout << 1;
	}
	else {
		cout << cnt;
	}

	return 0;
}