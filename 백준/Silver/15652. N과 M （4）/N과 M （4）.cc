#include <iostream>
#include <vector>

using namespace std;

void backtracking(int start, int& n, int& m, vector <int>& v) {
	if (v.size() == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 1; i <= n; i++) {
		if (i >= start) {
			v.push_back(i);
			backtracking(i, n, m, v);
			v.pop_back();
		}
	}
}

int main() {
	int n, m;
	vector<int> v;

	cin >> n >> m;

	backtracking(1, n, m, v);

	return 0;
}