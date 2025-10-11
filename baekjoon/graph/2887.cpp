// ���� : https://www.acmicpc.net/problem/2887
// ���� : �༺�ͳ�
// �˰��� : �ּ� ���д� Ʈ��(Prim-�˰���)

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <utility>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Prim �˰������� MST�� �� ����� ���ϴ� �Լ�
long long prim(vector<vector<pair<int, int>>>& nodes, int n) {
	vector<int> dist(n, INF);   // �� �������� �ּ� �Ÿ�
	vector<int> visit(n, 0);    // �湮 ����
	long long sum = 0;          // MST �� ���

	// �켱���� ť: (���, ���) ���·� �ּ� ��� ������ �켱 ����
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, 0 });   // ���� ���(0��) ��� 0���� ����
	dist[0] = 0;

	while (!q.empty()) {
		auto [cost, cur] = q.top();
		q.pop();

		if (visit[cur]) continue; // �̹� �湮�� ���� ��ŵ

		visit[cur] = 1;   // �湮 ó��
		sum += cost;      // MST�� ���Ե� ���� ��� ����

		// ���� ���� ������ ���� �˻�
		for (auto [w, v] : nodes[cur]) {
			// �湮���� �ʾҰ�, �� ª�� ��ΰ� �ִٸ� ����
			if (!visit[v] && w < dist[v]) {
				dist[v] = w;
				q.push({ w, v });
			}
		}
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// �� ��ǥ�ະ�� (��ǥ��, ����ȣ) ����
	vector<pair<int, int>> x_coords, y_coords, z_coords;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		x_coords.push_back({ x, i });
		y_coords.push_back({ y, i });
		z_coords.push_back({ z, i });
	}

	// �� �ະ�� ��ǥ ���� (���� ��峢�� �����ϱ� ����)
	sort(x_coords.begin(), x_coords.end());
	sort(y_coords.begin(), y_coords.end());
	sort(z_coords.begin(), z_coords.end());

	// �׷��� ���� ����Ʈ
	vector<vector<pair<int, int>>> nodes(n);

	// �־��� ��ǥ���� �������� ������ �� ���� �������� �����ϴ� �Լ�
	auto create_node = [&](vector<pair<int, int>>& coords) {
		for (int i = 0; i < n - 1; i++) {
			int u = coords[i].second;       // ���� ��� ��ȣ
			int v = coords[i + 1].second;   // ���� ��� ��ȣ
			int cost = abs(coords[i].first - coords[i + 1].first); // �Ÿ�(���� ����ġ)

			nodes[u].push_back({ cost, v });
			nodes[v].push_back({ cost, u });
		}
		};

	// x, y, z�� ���� ���� ������ ���鳢�� ����
	create_node(x_coords);
	create_node(y_coords);
	create_node(z_coords);

	// Prim �˰����� �̿��� �ּ� ���д� Ʈ���� �� ��� ���
	long long result = prim(nodes, n);

	cout << result;

	return 0;
}