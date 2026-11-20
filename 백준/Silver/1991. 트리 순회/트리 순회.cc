#include <iostream>

using namespace std;

struct Node {
    char p;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(char c) : p(c) {}
};

void preorder_traversal(Node* root) {
    if (root) {
        cout << root->p;
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(Node* root) {
    if (root) {
        inorder_traversal(root->left);
        cout << root->p;
        inorder_traversal(root->right);
    }
}

void postorder_traversal(Node* root) {
    if (root) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->p;
    }
}

int main() {
	int n;
	
    cin >> n;
    Node* nodes[26] = { nullptr };

    for (int i = 0; i < n; i++) {
        char p, l, r;

        cin >> p >> l >> r;

        if (!nodes[p - 'A']) {
            nodes[p - 'A'] = new Node(p);
        }

        if (l != '.') {
            if (!nodes[l - 'A']) {
                nodes[l - 'A'] = new Node(l);
            }
            nodes[p - 'A']->left = nodes[l - 'A'];
        }

        if (r != '.') {
            if (!nodes[r - 'A']) {
                nodes[r - 'A'] = new Node(r);
            }
            nodes[p - 'A']->right = nodes[r - 'A'];
        }
    }

    Node* root = nodes[0];

    preorder_traversal(root);
    cout << '\n';
    inorder_traversal(root);
    cout << '\n';
    postorder_traversal(root);

    return 0;
}