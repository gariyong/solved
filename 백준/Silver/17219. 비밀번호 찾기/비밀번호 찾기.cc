#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	int n, m;
	unordered_map <string, string> map;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		cin >> map[str];
	}

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		cout << map[str] << '\n';
	}

	return 0;
}