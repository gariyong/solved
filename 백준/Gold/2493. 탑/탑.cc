#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	int* top;
	int* result;
	stack<int> s;

	cin >> n;
	result = new int[n];
	top = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> top[i];
	}

	for (int i = 0; i < n; i++) {
		while (!s.empty() && top[s.top()] < top[i]) {
			s.pop();
		}

		if (!s.empty()) {
			result[i] = s.top() + 1;
		}
		else {
			result[i] = 0;
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << ' ';
	}

	delete[] top;
	delete[] result;
 
	return 0;
}