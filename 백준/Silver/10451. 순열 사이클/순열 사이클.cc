#include <iostream>

using namespace std;

typedef struct Node {
	int visit = 0;
	int nextNode = 0;
}Node;

int dfs(Node*& arr, int next) {
	if (arr[next].visit == 0) {
		arr[next].visit = 1;
		dfs(arr, arr[next].nextNode);
	}
	else if (arr[next].visit == 1) {
		return 1;
	}
	return 1;
}

int main() {
	int n, m;
	Node* arr;

	cin >> n;
	while (n--) {
		int cnt = 0;
		cin >> m;
		if (m > 0) {
			arr = new Node[m + 1];
			for (int i = 1; i <= m; i++) {
				cin >> arr[i].nextNode;
			}
			for (int i = 1; i <= m; i++) {
				if (arr[i].visit == 0) {
					cnt += dfs(arr, i);
				}
			}
			cout << cnt << '\n';

			delete[] arr;
		}
	}


	return 0;
}