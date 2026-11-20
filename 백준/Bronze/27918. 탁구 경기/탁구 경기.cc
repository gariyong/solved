#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, x = 0, y = 0;

	cin >> n;

	while (n--) {
		char c;
		
		cin >> c;
		if (c == 'D') {
			x++;
		}
		else {
			y++;
		}

		int result = abs(x - y);

		if (result == 2) {
			break;
		}
	}

	cout << x << ":" << y;

	return 0;
}