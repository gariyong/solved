#include <iostream>

using namespace std;

int main() {
	 double a, b;

	cin >> a >> b;

	double result = ((a / 100) * b);
	if (a - result < 100) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}