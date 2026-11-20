#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	queue <pair<int, int>> position;
	vector <int> visit(100001, 0);
	int n, k;

	cin >> n >> k;
	position.push({ n, 0 });
	
	while (!position.empty()) {
		int pos = position.front().first;
		int time = position.front().second;
		position.pop();
		visit[pos] = 1;


		if (pos == k) {
			cout << time;
			break;
		}

		int np[] = { pos - 1, pos + 1, pos * 2 };
		for (int i = 0; i < 3; i++) {
			if (np[i] >= 0 && np[i] <= 100000 && visit[np[i]] == 0) {
				position.push({ np[i], time + 1 });
			}
		}
	}

	return 0;
}