#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	priority_queue<long long, vector<long long>, greater<>> q;

	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;

		if (x > 0) q.push(x);
	}

	while (q.size() >= 2) {
		long long a = q.top();
		q.pop();
		
		long long b = q.top();
		q.pop();

		if (a == b) {
			q.push(a * 2);
		}
		else {
			q.push(b);
		}
	}

	if (q.empty()) {
		cout << 0;
	}
	else {
		cout << q.top();
	}

	return 0;
}