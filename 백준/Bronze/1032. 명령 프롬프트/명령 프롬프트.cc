#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string str1, str2;

	cin >> n;
	cin >> str1;

	for (int i = 0; i < n - 1; i++) {
		cin >> str2;
		for (int j = 0; j < str1.length(); j++) {
			if (str1[j] != str2[j]) {
				str1[j] = '?';
			}
		}
	}

	cout << str1;

	return 0;
}