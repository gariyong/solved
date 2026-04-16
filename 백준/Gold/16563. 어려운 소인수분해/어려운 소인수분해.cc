#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
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
        if (is_prime[i]) primes.push_back(i);
    }

    return primes;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes = sieve(n);
	vector<int>num(n);

    for (int i = 0; i < n; i++) {
		cin >> num[i];
    }

    for (int i = 0; i < n; i++) {
        for (int p : primes) {
            if (p * p > num[i]) {
                break;
            }

            int count = 0;
            while (num[i] % p == 0) {
                num[i] /= p;
                count++;
            }
            if (count > 0) {
                for (int i = 0; i < count; i++) {
                    cout << p << ' ';
                }
            }
        }
        if (num[i] > 1) {
            cout << num[i];
        }
		cout << '\n';
    }

    return 0;
}