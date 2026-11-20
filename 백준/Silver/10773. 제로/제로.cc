#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n;
	int sum = 0;
	stack<int>s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			s.pop();
		}
		else {
			s.push(num);
		}
	}

	for (int i = s.size(); i > 0; i--) {
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}