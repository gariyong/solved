#include <iostream>

using namespace std;

int main() {
	int x;
	int min = 0;
	int sec = 0;

	for (int i = 0; i < 4; i++) {
		cin >> x;
		sec += x;
	}

	min = sec / 60;
	sec %= 60;

	cout << min << '\n' << sec;

	return 0;
}