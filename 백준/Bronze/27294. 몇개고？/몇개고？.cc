#include <iostream>

using namespace std;

int main()
{
	int t, s;

	cin >> t >> s;

	if (s == 1) {
		cout << 280;
	}
	else {
		if (12 <= t && t <= 16) {
			cout << 320;
		}
		else {
			cout << 280;
		}
	}

	return 0;
}