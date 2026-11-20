#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	int num = 1;
	int* line;
	stack<int> s;

	cin >> n;
	line = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> line[i];
		if (line[i] == num) {
			num++;
		}
		else {
			s.push(line[i]);
		}
		while (!s.empty() && s.top() == num) {
			num++;
			s.pop();
		}
	}

	if (num == n + 1) {
		cout << "Nice";
	}
	else {
		cout << "Sad";
	}
	delete[] line;

	return 0;
}