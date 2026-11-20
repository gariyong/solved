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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<int> primes = sieve(1000);

    while (T--) {
        int n;
        cin >> n;
        bool found = false;

        for (int i = 0; i < (int)primes.size() && !found; i++) {
            for (int j = 0; j < (int)primes.size() && !found; j++) {
                for (int k = 0; k < (int)primes.size(); k++) {
                    if (primes[i] + primes[j] + primes[k] == n) {
                        cout << primes[i] << " " << primes[j] << " " << primes[k] << "\n";
                        found = true;
                        break;
                    }
                }
            }
        }

        if (!found) cout << 0 << "\n";
    }

    return 0;
}