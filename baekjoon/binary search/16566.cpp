// 문제 : https://www.acmicpc.net/problem/16566
// 제목 : 카드 게임

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> deck(m);
	for (int i = 0; i < m; i++) {
		cin >> deck[i];
	}
	sort(deck.begin(), deck.end());

	vector<int> cards(k);
	vector<bool> used(m, false);
	for (int i = 0; i < k; i++) {
		cin >> cards[i];
	}

	for (int x : cards) {
		int left = 0;
		int right = m - 1;

		while (left < right) {
			int mid = (left + right) / 2;

			if (deck[mid] > x) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}

		int idx = left;
		while (idx < m && used[idx]) {
			idx++;
		}

		cout << deck[idx] << '\n';
		used[idx] = true;
	}

	return 0;
}
