#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	Node* parent = nullptr;
	vector<Node*> children;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, start, cnt = 0;

	cin >> n;
	vector<Node> nodes(n);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x == -1) {
			start = i;
		}
		else {
			nodes[i].parent = &nodes[x];
			nodes[x].children.push_back(&nodes[i]);
		}
	}

	cin >> m;

	if (start == m) {
		cout << 0;

		return 0;
	}

	queue<Node*> q;
	q.push(&nodes[start]);

	while (!q.empty()) {
		bool erased = false;

		Node* cur = q.front();
		q.pop();

		for (int i = 0; i < cur->children.size(); i++) {
			if (cur->children[i] == &nodes[m]) {
				cur->children.erase(cur->children.begin() + i);
				erased = true;
				break;
			}
			q.push(cur->children[i]);
		}

		if (erased) {
			break;
		}
	}

	q = queue<Node*>();
	q.push(&nodes[start]);

	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();

		if (cur->children.empty()) {
			cnt++;
		}
		else {
			for (Node* child : cur->children) {
				if (child == &nodes[m]) {
					continue;
				}
				q.push(child);
			}
		}
	}

	cout << cnt;

	return 0;
}