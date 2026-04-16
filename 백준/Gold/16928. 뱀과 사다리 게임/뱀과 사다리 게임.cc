#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, m;
	queue<int> q;
	vector<int> board(101, 0);
	vector<int> visit(101, 0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		board[x] = y;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		board[x] = y;
	}

	q.push(1);
	visit[1] = 0;

	while (!q.empty()) {
		int player = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next = player + i;
			if (next <= 100) {

				if (board[next] != 0) {
					next = board[next];
				}

				if (visit[next] == 0) {
					visit[next] = visit[player] + 1;
					q.push(next);
				}
			}
		}
	}

	cout << visit[100];
	return 0;
}