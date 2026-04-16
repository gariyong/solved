#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int> max_q;
	priority_queue<int, vector<int>, greater<int>> min_q;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (max_q.size() == min_q.size()) {
			max_q.push(num);
		}
		else {
			min_q.push(num);
		}

		if (!min_q.empty() && max_q.top() > min_q.top()) {
			int max_val = max_q.top();
			max_q.pop();

			int min_val = min_q.top();
			min_q.pop();

			max_q.push(min_val);
			min_q.push(max_val);
		}

		cout << max_q.top() << '\n';
	}

	return 0;
}