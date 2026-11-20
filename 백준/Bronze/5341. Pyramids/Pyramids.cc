#include <iostream>

using namespace std;

int main() {
	while (true) {
		int n, sum = 0;
		
		cin >> n;
		
		if (n == 0) {
			break;
		}
		else {
			for (n; n > 0; n--) {
				sum += n;
			}
		}

		cout << sum << '\n';
	}

	return 0;
}