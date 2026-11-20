#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtracking(int start, int& n, int& m, vector <int>& v, vector <int>& num, vector<int>& visit) {
	if (v.size() == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i] == 0) {
			v.push_back(num[i]);
			visit[i] = 1;
			backtracking(num[i], n, m, v, num, visit);
			v.pop_back();
			visit[i] = 0;
		}
	}
}

int main() {
	int n, m;
	vector<int> v;
	
	cin >> n >> m;
	vector<int> num(n);
	vector<int> visit(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());

	backtracking(num[0], n, m, v, num, visit);

	return 0;
}