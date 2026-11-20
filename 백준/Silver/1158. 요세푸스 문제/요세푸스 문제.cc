#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, k;
	queue<int>q;
	queue<int>answer;

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		int num;
		for (int i = 0; i < k - 1; i++) {
			num = q.front();
			q.pop();
			q.push(num);
		}
		answer.push(q.front());
		q.pop();
	}
	answer.push(q.front());

	cout << '<';
	for (int i = 0; i < n - 1; i++) {
		cout << answer.front() << ", ";
		answer.pop();
	}
	cout << answer.front() << '>';

	return 0;
}