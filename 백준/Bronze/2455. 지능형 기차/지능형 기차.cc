#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int in = -1;
	int out = -1;

	int result = 0;
	int people = 0;
	while (in != 0) {
		cin >> out >> in;

		people -= out;
		people += in;
		result = max(result, people);
	}

	cout << result;

	return 0;
}