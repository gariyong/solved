#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int cnt = 0;
	for (auto& x : str) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}