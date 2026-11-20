#include <iostream>

using namespace std;

int main() {
	int money = 100;
	int n, m;

	cin >> n >> m;
	money *= n;

	if (money >= m) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}