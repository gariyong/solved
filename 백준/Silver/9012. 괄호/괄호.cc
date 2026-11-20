#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		stack<char>s;
		bool flag = 0;
		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				s.push(str[i]);
			}
			else if (!s.empty() && str[i] == ')') {
				s.pop();
				flag = 1;
			}
			else if (s.empty() && str[i] == ')') {
				flag = 0;
				break;
			}
		}

		if (s.empty() && flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}