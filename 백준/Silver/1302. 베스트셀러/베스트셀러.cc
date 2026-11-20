#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	map<string, int> books;

	for (int i = 0; i < n; i++) {
		string title;
		cin >> title;

		if (books.find(title) == books.end()) {
			books[title] = 1;
		} else {
			books[title]++;
		}
	}

	int max_cnt = 0;
	string result;
	for (auto& [title, cnt] : books) {
		if (cnt > max_cnt) {
			max_cnt = cnt;
			result = title;
		}
	}

	cout << result;

	return 0;
}