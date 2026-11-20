#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int score = 0;
	for (char c : s) {
		score += (c - 'A') + 1;
	}

	cout << score;

	return 0;
}