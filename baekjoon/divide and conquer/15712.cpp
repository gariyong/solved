// ���� : https://www.acmicpc.net/problem/15712
// ���� : ������

#include <iostream>

using namespace std;

// �ŵ����� �Լ�
long long mod_pow(long long base, long long exp, int mod) {
    long long result = 1;     // ���� ���
    long long b = base % mod; // base�� mod�� �̸� ���� ������

    while (exp > 0) {
        // ���� ������ Ȧ���� ����� b�� ����
        if (exp % 2 == 1) {
            result = (result * b) % mod;
        }

        // b�� �����ϰ� mod ����
        b = (b * b) % mod;
        // ������ �������� ����
        exp = exp / 2;
    }

    return result;
}

// ������ �� ����ϴ� �Լ�
// a : ���� r : ����, n : ���� ����, mod : ������ ���� ��
long long divide_seq(long long a, long long r, long long n, int mod) {
    // ���� 1���� a % mod ��ȯ
    if (n == 1) {
        return a % mod;
    }

    // n�� ¦���� ���
    if (n % 2 == 0) {
        long long half = divide_seq(a, r, n / 2, mod); // ���� ���� �� ���
        long long pow_val = mod_pow(r, n / 2, mod);    // r^(n/2) % mod ���

        // ������ �� ����: S_n = S_(n/2) * (1 + r^(n/2))
        return (half * (1 + pow_val)) % mod;
    }

    // n�� Ȧ���� ���
    else {
        long long prev = divide_seq(a, r, n - 1, mod); // �� n-1�� ��
        long long pow_val = mod_pow(r, n - 1, mod);    // r^(n-1) % mod ���
        long long term = (a * pow_val) % mod;          // ������ ��

        // �� �κ� �� + ������ �κ� ��
        return (prev + term) % mod;
    }
}

int main() {
    long long a, r, n;
    int mod;

    // a : ���� r : ����, n : ���� ����, mod : ������ ���� �� �Է�
    cin >> a >> r >> n >> mod;

    // ������ �� ���
    long long answer = divide_seq(a, r, n, mod);

    // ��� ���
    cout << answer;

    return 0;
}