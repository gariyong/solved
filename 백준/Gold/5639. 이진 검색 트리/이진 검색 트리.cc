#include <iostream>

using namespace std;

typedef struct Node {
	int data;
	Node* left = NULL;
	Node* right = NULL;
	
	Node(int val) : data(val), left(NULL), right(NULL) {}
}Node;

void insert(Node*& root, int val) {
	if (root == NULL) {
		root = new Node(val);
		return;
	}

	if (val < root->data) {
		insert(root->left, val);
	}
	else if (val > root->data) {
		insert(root->right, val);
	}
}


void postorder(Node* root) {
	if (!root) {
		return;
	}

	postorder(root->left);
	postorder(root->right);

	cout << root->data << '\n';
}

int main() {
	Node* root = NULL;
	int num;

	while (cin >> num) {
		insert(root, num);
	}

	postorder(root);

	return 0;
}