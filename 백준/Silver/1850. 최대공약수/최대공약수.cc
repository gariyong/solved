#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    long long a, b;
    cin >> a >> b;

    long long cnt = gcd(a, b);

    for (long long i = 0; i < cnt; i++) {
        cout << 1;
    }

    return 0;
}