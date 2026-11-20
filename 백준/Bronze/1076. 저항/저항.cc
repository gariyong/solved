#include <iostream>
#include <string>

using namespace std;

int main() {
	string color[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
	string input;
	int n[3];
	long long resistance = 0;

	for (int i = 0; i < 3; i++) {
		cin >> input;

		for (int j = 0; j < 10; j++) {
			if (color[j] == input) {
				n[i] = j;
			}
		}
	}

	resistance += n[0] * 10 + n[1];
	for (int i = 0; i < n[2]; ++i) {
		resistance *= 10;
	}
	cout << resistance;
}