// ���� : https://www.acmicpc.net/problem/10775
// ���� : ����
// �˰��� : union-find

#include <iostream>
#include <vector>

using namespace std;


// find �Լ� : �־��� ����Ʈ x�� ���� ��Ʈ(��, ���� ��ŷ ������ ���� ū ����Ʈ ��ȣ)�� ã�´�.
// ��� ����(Path Compression)�� �̿��� ȿ�������� �θ� �����Ѵ�.
int find(vector<int>& parent, int x) {
	if (parent[x] == x) {
		return x; // �ڱ� �ڽ��� ��Ʈ��� �״�� ��ȯ
	}
	return parent[x] = find(parent, parent[x]); // ��Ʈ�� ã�ư��鼭 �θ� ����
}

// unite �Լ� : �� ����(����Ʈ)�� ��ģ��.
// a ����Ʈ�� b ����Ʈ�� ���� �� ��, a ����Ʈ�� ���� ����� �� ����, ������ b ����Ʈ�� ������� �ǹ�
void unite(vector<int>& parent, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);
	parent[a] = b; // a�� ��Ʈ�� b�� ����
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int g, p;
	cin >> g >> p; // g: ����Ʈ ��, p: ����� ��

	// parent �迭 �ʱ�ȭ: i�� ����Ʈ�� �θ� �ڱ� �ڽ����� ����
	vector<int> gate(g + 1);
	for (int i = 0; i <= g; i++) {
		gate[i] = i;
	}

	int cnt = 0; // ��ŷ ������ ����� ��
	for (int i = 0; i < p; i++) {
		int g_i;
		cin >> g_i; // �� ����Ⱑ ��ŷ�Ϸ��� �ִ� ����Ʈ ��ȣ

		// ���� ����Ⱑ ��ŷ ������ ���� ū ����Ʈ ��ȣ�� ã��
		int docking_gate = find(gate, g_i);

		// docking_gate == 0 �̸� �� �̻� ��ŷ�� �� �ִ� ����Ʈ�� ����
		if (docking_gate == 0) break;

		// docking_gate ����Ʈ�� ��ŷ �Ϸ�
		// ���� �� ����Ʈ�� ��� �Ұ����ϹǷ�, ������ docking_gate - 1�� ����
		unite(gate, docking_gate, docking_gate - 1);

		cnt++; // ��ŷ ����
	}

	cout << cnt; // ��ŷ ������ �ִ� ����� �� ���

	return 0;
}