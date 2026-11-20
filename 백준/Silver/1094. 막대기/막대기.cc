#include <iostream>

using namespace std;

int main() {
	int x;
	int stick = 64;
	int count = 0;

	cin >> x;
	while (x > 0) {
		if (stick <= x) {
			x -= stick;
			count++;
		}
		stick /= 2;
	}
	cout << count;

	return 0;
}