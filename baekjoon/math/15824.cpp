// ���� : https://www.acmicpc.net/problem/15824
// ���� : �� ������ ĸ���̽��� ���ִܴ�

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007; // ��ⷯ ���� ��

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n; // �޴� ���� �Է�

	vector<long long>menu(n);
	for (int i = 0; i < n; i++) {
		cin >> menu[i];
	}
	// �������� ����
	// menu[i]�� �ִ�/�ּ� ���� Ƚ���� ī��Ʈ�ϱ� ���ؼ�
	sort(menu.begin(), menu.end());


	// 2�� �ŵ����� �̸� ���
	vector<long long> pow2(n);
	pow2[0] = 1;
	for (int i = 1; i < n; i++) {
		pow2[i] = (pow2[i - 1] * 2) % MOD;
	}

	long long result = 0;
	for (int i = 0; i < n; i++) {
		// menu[i]�� �ִ밪���� �����ϴ� �κ����� �� : 2^i
		long long max_contrib = (menu[i] * pow2[i]) % MOD;

		// menu[i]�� �ּڰ����� �����ϴ� �κ����� �� : 2^(n - i - 1)
		long long min_contrib = (menu[i] * pow2[n - i - 1]) % MOD;

		// �� �޴��� �⿩�� = max �⿩�� - min �⿩��
		// ������ ���� �� �����Ƿ� MOD�� �����༭ ����(�߿�)
		result += (max_contrib - min_contrib + MOD) % MOD;
		result %= MOD;
	}

	// ��� ���
	cout << result;

	return 0;
}