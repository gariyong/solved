#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node {
	map<string, Node*> child;
};

void insert(Node* root, vector<string>& foods) {
	Node* cur = root;
	for (auto& food : foods) {
		if(!cur->child.count(food)) {
			cur->child[food] = new Node();
		}

		cur = cur->child[food];
	}
}

void dfs(Node* cur, int depth) {
	for (auto& [food, next] : cur->child) {
		cout << string(depth * 2, '-') << food << '\n';

		dfs(next, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	Node* root = new Node();
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		vector<string> foods(x);
		for (int j = 0; j < x; j++) {
			cin >> foods[j];
		}

		insert(root, foods);
	}

	dfs(root, 0);

	return 0;
}