// 문제: https://www.acmicpc.net/problem/30805
// 제목: 사전 순 최대 공통 부분 수열

// 처음에는 주어진 조건대로 찾는 방법을 구현하려했으나, 코드를 작성하는 과정에서 복잡함을 느꼈고,
// 주어진 조건을 만족하는 수를 찾는 방법이 현재 위치에서 다음 위치로 이동시켜서 가장 큰 수를 찾는 것이
// 가장 효율적이라는 것을 깨달았다. 따라서, 각 배열에서 현재 위치 이후로 가장 큰 수를 찾아서
// 그 수를 결과에 추가하고, 해당 위치로 이동하는 방식으로 구현하였다.

#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& str, int start, int target) {
	for (int i = start; i < str.size(); i++) {
		if (str[i] == target) {
			return i;
		}
	}

	return -1;
}

int main() {
	int n, m;

	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> m;
	vector<int> b(m);

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int i = 0, j = 0;
	vector<int> result;

	while (i < n && j < m) {
		int max_element = -1;

		for (int num = 100; num >= 1; num--) {
			int next_a = find(a, i, num);
			int next_b = find(b, j, num);

			if (next_a != -1 && next_b != -1) {
				max_element = num;
				i = next_a + 1;
				j = next_b + 1;
				result.push_back(max_element);

				break;
			}
		}

		if (max_element == -1) {
			break;
		}
	}

	cout << result.size() << endl;
	if (!result.empty()) {
		for (int k = 0; k < result.size(); k++) {
			cout << result[k] << " ";
		}
	}

	return 0;
}