// 문제 : https://www.acmicpc.net/problem/15712
// 제목 : 등비수열

#include <iostream>

using namespace std;

// 거듭제곱 함수
long long mod_pow(long long base, long long exp, int mod) {
    long long result = 1;     // 최종 결과
    long long b = base % mod; // base를 mod로 미리 나눈 나머지

    while (exp > 0) {
        // 현재 지수가 홀수면 결과에 b를 곱함
        if (exp % 2 == 1) {
            result = (result * b) % mod;
        }

        // b를 제곱하고 mod 연산
        b = (b * b) % mod;
        // 지수를 절반으로 줄임
        exp = exp / 2;
    }

    return result;
}

// 등비수열 합 계산하는 함수
// a : 초항 r : 공비, n : 항의 개수, mod : 나머지 연산 값
long long divide_seq(long long a, long long r, long long n, int mod) {
    // 항이 1개면 a % mod 반환
    if (n == 1) {
        return a % mod;
    }

    // n이 짝수일 경우
    if (n % 2 == 0) {
        long long half = divide_seq(a, r, n / 2, mod); // 절반 길이 합 계산
        long long pow_val = mod_pow(r, n / 2, mod);    // r^(n/2) % mod 계산

        // 등비수열 합 공식: S_n = S_(n/2) * (1 + r^(n/2))
        return (half * (1 + pow_val)) % mod;
    }

    // n이 홀수일 경우
    else {
        long long prev = divide_seq(a, r, n - 1, mod); // 앞 n-1개 합
        long long pow_val = mod_pow(r, n - 1, mod);    // r^(n-1) % mod 계산
        long long term = (a * pow_val) % mod;          // 마지막 항

        // 앞 부분 합 + 마지막 부분 합
        return (prev + term) % mod;
    }
}

int main() {
    long long a, r, n;
    int mod;

    // a : 초항 r : 공비, n : 항의 개수, mod : 나머지 연산 값 입력
    cin >> a >> r >> n >> mod;

    // 등비수열 합 계산
    long long answer = divide_seq(a, r, n, mod);

    // 결과 출력
    cout << answer;

    return 0;
}