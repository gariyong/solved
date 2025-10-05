// ���� : https://www.acmicpc.net/problem/1052
// ���� : ����

#include <iostream>

using namespace std;

// ������ ��ĥ �� �ִ� ��ŭ ��ģ ��, ���� ������ ������ ����ϴ� �Լ�
int count_bottles(int n) {
	int cnt = 0;

	// n�� 0�� �� ������ �ݺ�
	while (n > 0) {
		// n�� Ȧ����, ���� �ϳ� ���´ٴ� �ǹ� (2���� ��ġ�� 1�� ����)
		if (n % 2 == 1) cnt++;

		// 2���� ���� ��ġ�� �� n�� 2�� ������ ���� ũ���� �� ������ ��
		n /= 2;
	}

	return cnt; // ���� ���� ���� ��ȯ
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k; // n : ���� ���� ������ ����, k : �ִ�� ���� �� �ִ� ������ ����

	int cnt = 0; // ���� ��� �ϴ� ������ ��

	while (true) {
		// ���� �� ������ ��� ������ ��, ���� ���� k�� ���϶�� ����
		if (count_bottles(n) <= k) break;

		// �ƴ϶�� ������ �ϳ� �� ����
		n++;
		cnt++;
	}

	cout << cnt; // �߰��� ��� �ϴ� �ּ� ���� ���� ���

	return 0;
}