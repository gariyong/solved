#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> str(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> str[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		reverse(str[i].begin(), str[i].end());
		for (int j = 0; j < m; j++) {
			cout << str[i][j];
		}
		cout << '\n';
	}

	return 0;
}