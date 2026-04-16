#include <iostream>
#include <set>

using namespace std;

int main() {
	int t;

	cin >> t;

	while (t > 0) {
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int k;
		multiset <int> ms;

		cin >> k;

		while (k > 0) {
			char input;
			int n;

			cin.ignore();
			cin >> input >> n;

			if (input == 'I') {
				ms.insert(n);
			}
			else if (input == 'D' && !ms.empty()) {
				if (n == 1) {
					ms.erase(prev(ms.end()));
				}
				else if (n == -1) {
					ms.erase(ms.begin());
				}
			}

			k--;
		}

		if (ms.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
		}

		t--;
	}

	return 0;
}