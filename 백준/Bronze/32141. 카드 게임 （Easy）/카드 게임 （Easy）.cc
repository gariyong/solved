#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, hp;
	cin >> n >> hp;

	vector<int> cards(n);
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	for (int i = 0; i < n; i++) {
		hp -= cards[i];

		if(hp <= 0) {
			cout << i + 1;

			return 0;
		}
	}

	cout << -1;

	return 0;
}