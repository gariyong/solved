#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n, m;
	string command;
	stack<int>s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> command;

		if (command == "push") {
			cin >> m;
			s.push(m);
		}
		if (command == "top") {
			if (!s.empty()) {
				cout << s.top() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		if (command == "pop") {
			if (!s.empty()) {
				cout << s.top() << endl;
				s.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
		if (command == "size") {
			cout << s.size() << endl;
		}
		if (command == "empty") {
			if (s.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
	}

	return 0;
}