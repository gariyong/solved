#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str, bomb;
	stack <char> s;
	int cnt = 0;
	int n;
	vector <char> result;

	cin >> str >> bomb;

	int c4_len = bomb.length();
	int str_len = str.length();
	
	for (int i = 0; i < str_len; i++) {
		s.push(str[i]);

		if (s.size() >= c4_len && s.top() == bomb[c4_len - 1]) {
			bool flag = true;

			for (int j = 0; j < c4_len; j++) {
				if (s.top() != bomb[c4_len - 1 - j]) {
					flag = false;
					n = j;
					break;
				}
				s.pop();
			}

			if (!flag) {
				for (int j = n; j > 0; j--) {
					s.push(bomb[c4_len-j]);
				}
			}
		}
	}

	while (!s.empty()) {
		result.push_back(s.top());
		s.pop();
	}

	if (result.empty()) {
		cout << "FRULA";
	}
	else {
		int res_len = result.size();
		for (int i = res_len; i > 0; i--) {
			cout << result[i - 1];
		}
	}

	return 0;
}