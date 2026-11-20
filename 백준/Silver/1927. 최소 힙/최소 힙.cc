#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue <int, vector<int>, greater<int>> q;
	int n;

	cin >> n;

	while (n > 0) {
		int x;
		cin >> x;

		if (x == 0 && q.empty()) {
			cout << 0 << '\n';
		}
		else if (x == 0 && !q.empty()) {
			cout << q.top() << '\n';
			q.pop();
		}
		else {
			q.push(x);
		}
		n--;
	}

	return 0;
}