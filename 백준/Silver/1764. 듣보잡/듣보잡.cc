#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int cnt = 0;
	unordered_map<string, string> map;
	vector<string> v;

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		map[name] = name;
	}

	while (m > 0) {
		string name;
		cin >> name;
		if (map.find(name) != map.end()) {
			cnt++;
			v.push_back(map[name]);
		}
		m--;
	}

	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << v[i] << '\n';
	}

	return 0;
}