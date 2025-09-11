// 巩力 : https://www.acmicpc.net/problem/1644
// 力格 : 家荐狼 楷加钦

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, cnt = 0;
	vector<bool> is_prime(4000001, true);

	cin >> n;
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}

	vector<int> primes;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
		}
	}

	int left = 0, right = 0, sum = 0;
	while (true) {
		if (sum >= n) {
			sum -= primes[left++];
		}
		else if (right == primes.size()) {
			break;
		}
		else {
			sum += primes[right++];
		}

		if (sum == n) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}