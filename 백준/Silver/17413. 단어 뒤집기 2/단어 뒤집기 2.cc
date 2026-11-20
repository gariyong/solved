#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string S, sentence;
	stack<char>s;

	getline(cin, S);
	S.push_back(' ');

	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '<') {
			while (!s.empty()) {
				sentence.push_back(s.top());
				s.pop();
			}
			while (S[i] != '>') {
				sentence.push_back(S[i]);
				i++;
			}
			sentence.push_back('>');
		}
		else if (S[i] == ' ') {
			while (!s.empty()) {
				sentence.push_back(s.top());
				s.pop();
			}
			sentence.push_back(' ');
		}
		else {
			s.push(S[i]);
		}
	}

	int n = sentence.length();
	for (int i = 0; i < n; i++) {
		cout << sentence[i];
	}

	return 0;
}