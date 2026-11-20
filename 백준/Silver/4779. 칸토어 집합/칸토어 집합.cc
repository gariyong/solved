#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void divide(vector<char>& str, int start, int end) {
	if (end - start <= 1) return;

	int third = (end - start + 1) / 3;
	for(int i = start + third; i < end - third; i++) {
		str[i] = ' ';
	}

	for(int i = 0; i < 3; i++) {
		divide(str, start + i * third, start + (i + 1) * third);
	}
}

int main() {
	int n;
	while (cin >> n) {
		vector<char> str((int)pow(3, n), '-');

		divide(str, 0, (int)str.size());

		for (char x : str) {
			cout << x;
		}
		cout << '\n';
	}

	return 0;
}