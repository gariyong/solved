// 문제: https://www.acmicpc.net/problem/1918
// 제목: 후위 표기식

// 처음엔 우선순위 없이 해보려했지만 연산자 우선순위를 고려해서 풀어야 코드가 간결하고 반례가 없었다.
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
