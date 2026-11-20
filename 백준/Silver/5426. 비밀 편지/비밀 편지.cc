#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int n;
	double len;
	string letter;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> letter;
		len = sqrt(letter.length());
		for (int j = 1; j <= len; j++) {
			for (int k = 1; k <= len; k++) {
				cout << letter[(int)len * k - j];
			}
		}
		cout << '\n';
	}

	return 0;
}