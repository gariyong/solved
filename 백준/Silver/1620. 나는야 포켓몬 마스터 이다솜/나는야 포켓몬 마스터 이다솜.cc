#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string* pokemon;
	unordered_map <string, int> map;

	cin >> n >> m;
	pokemon = new string[n];

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		pokemon[i] = str;
		map[str] = i + 1;
	}

	while (m > 0) {
		string str;
		cin >> str;
		if (isdigit(str[0])) {
			cout << pokemon[stoi(str) - 1] << '\n';
		}
		else {
			cout << map[str] << '\n';
		}
		m--;
	}
	delete[] pokemon;

	return 0;
}