#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	int num = 0;
	bool flag = true;
	vector<char>v;
	stack<int>s;

	s.push(num);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;

		while (s.top() < m) {
			num++;
			s.push(num);
			v.push_back('+');
		}

		if (s.top() == m) {
			s.pop();
			v.push_back('-');
		}
		else {
			flag = false;
		}
	}

	if (flag == false) {
		cout << "NO";
	}
	else {
		int size = v.size();
		for (int i = 0; i < size; i++) {
			cout << v[i] << "\n";
		}
	}

	return 0;
}