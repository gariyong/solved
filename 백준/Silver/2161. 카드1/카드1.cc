#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, m;
	queue<int> q;

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	for (int i = 0; i < n - 1; i++) {
		cout << q.front() << ' ';
		q.pop();
		m = q.front();
		q.pop();
		q.push(m);
	}
	cout << q.front();

	return 0;
}