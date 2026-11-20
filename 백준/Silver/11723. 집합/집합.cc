#include <iostream>
#include <bitset>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	bitset<21> b;

	cin >> n;
	while (n--) {
		int m;
		string str;

		cin >> str;
		if (str == "add") {
			cin >> m;
			b.set(m);
		}
		else if (str == "remove") {
			cin >> m;
			b.reset(m);
		}
		else if (str == "check") {
			cin >> m;
			cout << b[m] << '\n';
		}
		else if (str == "toggle") {
			cin >> m;
			b.flip(m);
		}
		else if (str == "all") {
			b.set();
		}
		else if (str == "empty") {
			b.reset();
		}
	}

	return 0;
}