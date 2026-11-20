#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string str;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int len = (int) str.length();

		if (len >= 6 && len <= 9) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}