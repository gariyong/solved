#include <iostream>

using namespace std;

long long mod_pow(long long base, long long exp, int mod) {
    long long result = 1;
    long long b = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * b) % mod;
        }

        b = (b * b) % mod;
        exp = exp / 2;
    }

    return result;
}

long long divide_seq(long long a, long long r, long long n, int mod) {
    if (n == 1) {
        return a % mod;
    }

    if (n % 2 == 0) {
        long long half = divide_seq(a, r, n / 2, mod);
        long long pow_val = mod_pow(r, n / 2, mod);

        return (half * (1 + pow_val)) % mod;
    }
    else {
        long long prev = divide_seq(a, r, n - 1, mod);
        long long pow_val = mod_pow(r, n - 1, mod);
        long long term = (a * pow_val) % mod;

        return (prev + term) % mod;
    }
}

int main() {
    long long a, r, n;
    int mod;

    cin >> a >> r >> n >> mod;

    long long answer = divide_seq(a, r, n, mod);

    cout << answer;

    return 0;
}