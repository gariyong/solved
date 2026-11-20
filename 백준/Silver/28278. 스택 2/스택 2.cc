#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n, m;
	stack<int>s;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == 1) {
			int x;
			cin >> x;
			s.push(x);
		}
		if (m == 2) {
			if (!s.empty()) {
				cout << s.top() << "\n";
				s.pop();
			}
			else {
				cout << -1 << "\n";
			}
		}
		if (m == 3) {
			cout << s.size() << "\n";
		}
		if (m == 4) {
			if (s.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		if (m == 5) {
			if (!s.empty()) {
				cout << s.top() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
	}

	return 0;
}