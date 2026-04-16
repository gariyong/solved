#include <iostream>
#include <deque>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int MAX = 100001;

int main() {
	int n, k;
	deque <int> q;
	vector<int>pos(MAX, INF);

	cin >> n >> k;
	pos[n] = 0;

	q.push_back(n);

	while (!q.empty()) {
		int cur = q.front();
		q.pop_front();

		if (cur * 2 < MAX && pos[cur * 2] > pos[cur]) {
			pos[cur * 2] = pos[cur];
			q.push_front(cur * 2);
		}

		if (cur - 1 >= 0 && pos[cur - 1] > pos[cur] + 1) {
			pos[cur - 1] = pos[cur] + 1;
			q.push_back(cur - 1);
		}

		if (cur + 1 < MAX && pos[cur + 1] > pos[cur] + 1) {
			pos[cur + 1] = pos[cur] + 1;
			q.push_back(cur + 1);
		}
	}

	cout << pos[k];

	return 0;
}