#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void preorder(vector<int>& in, vector<int>& post, unordered_map<int, int>& idx, int in_start, int in_end, int post_start, int post_end) {
	if (in_start > in_end || post_start > post_end) return;

	int root = post[post_end];
	cout << root << ' ';

	int root_idx = idx[root];
	int left = root_idx - in_start;

	preorder(in, post, idx, in_start, root_idx - 1, post_start, post_start + left - 1);
	preorder(in, post, idx, root_idx + 1, in_end, post_start + left, post_end - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> in(n);
	vector<int> post(n);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}

	unordered_map<int, int> idx;
	for (int i = 0; i < n; i++) {
		idx[in[i]] = i;
	}

	preorder(in, post, idx, 0, n - 1, 0, n - 1);

	return 0;
}