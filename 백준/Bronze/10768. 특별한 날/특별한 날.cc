#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	if (a == 2) {
		if (b == 18) {
			cout << "Special";
		}
		else if (b < 18) {
			cout << "Before";
		}
		else {
			cout << "After";
		}
	}
	else if (a < 2) {
		cout << "Before";
	}
	else {
		cout << "After";
	}

	return 0;
}