#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int len;

	cin >> len >> str;

	for (int i = 0; i < len; i++) {
		if (str[i] == 'l') {
			cout << 'L';
		}
		else {
			cout << 'i';
		}
	}

	return 0;
}