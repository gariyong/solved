#include <iostream>
#include <stack>
#include <string>

using namespace std;

int priority(char op) {
	if (op == '(') return 0;
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return -1;
}

int main() {
	string s;
	stack<char> st;

	cin >> s;

	for (char ch : s) {
		if ('A' <= ch && ch <= 'Z') {
			cout << ch;
		}
		else if (ch == '(') {
			st.push(ch);
		}
		else if (ch == ')') {
			while (!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			while (!st.empty() && priority(st.top()) >= priority(ch)) {
				cout << st.top();
				st.pop();
			}
			st.push(ch);
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}