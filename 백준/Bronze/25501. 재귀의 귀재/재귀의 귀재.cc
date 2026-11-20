#include <iostream>
#include <string>

using namespace std;

int count = 0;

int recursion(string& s, int l, int r) {
	:: count++;
	if (l >= r) {
		return 1;
	}
	if (s[l] != s[r]) {
		return 0;
	}

	return recursion(s, l + 1, r - 1);
}

int isPalindrome(string& s) {
	return recursion(s, 0, s.length() - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string str;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		::count = 0;
		cout << isPalindrome(str) << ' ' << ::count << '\n';
	}

	return 0;
}