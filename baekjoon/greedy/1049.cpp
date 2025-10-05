// ���� : https://www.acmicpc.net/problem/1049
// ���� : ��Ÿ��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �� �귣�庰 ��Ÿ�� ���� ���� ����ü
struct Guitar_str {
	int individual; // ���� ����
	int package; // 6�� ����(��Ű��) ����
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m; // n : �ʿ��� ��Ÿ�� ��, m : �귣�� ��

	vector<Guitar_str>strings(m);
	for (int i = 0; i < m; i++) {
		// �� �귣���� ��Ű�� ���ݰ� ���� ���� �Է�
		cin >> strings[i].package >> strings[i].individual;
	}

	int min_6str = 1e9; // 6�� ���� �ּ� ���� ���
	int min_1str = 1e9; // 1�� ���� �ּ� ���� ���

	// ��� �귣�带 ��ȸ�ϸ� �ּ� ���� ���
	for (auto& cur : strings) {
		// 6���� ������ ��°� ��Ű������ �����Ҽ��� �����Ƿ� �� �� �귣�� ã��
		min_6str = min(min_6str, min(cur.individual * 6, cur.package));

		// ���� �߿��� ���� ������ �귣�� ã��
		min_1str = min(min_1str, cur.individual);
	}

	int result;
	
	// �ʿ��� ��Ÿ�� ���� n�� 6���� ������ �������� �ʴ� ���
	if (n % 6 != 0) {
		// �� ���� ��� �� ���� ������ ���� ����
		// ��Ű���θ� ���(���� �� ����) | ��Ű�� + ���� ȥ�� ����
		result = min(min_6str * (n / 6 + 1), min_6str * (n / 6) + min_1str * (n % 6));
	}
	// 6���� ��Ȯ�� ������ �������� ���
	else {
		// �ΰ��� ��� �� ���� ������ ���� ����
		// ���� ��Ű���θ� ���� | ���� �����θ� ����
		result = min(min_6str * (n / 6), min_1str * n);
	}

	cout << result; // �ּ� ��� ���

	return 0;
}