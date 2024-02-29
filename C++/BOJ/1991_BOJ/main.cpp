#include <iostream>

using namespace std;

struct TreeNode {
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char num) : val(num), left(NULL), right(NULL) {}
};

void preorder(TreeNode* node) {
	if (node == NULL) return;

	cout << node->val;
	preorder(node->left);
	preorder(node->right);
}

void inorder(TreeNode* node) {
	if (node == NULL) return;

	inorder(node->left);
	cout << node->val;
	inorder(node->right);
}

void postorder(TreeNode* node) {
	if (node == NULL) return;

	postorder(node->left);
	postorder(node->right);
	cout << node->val;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N;
	char n, l, r;
	TreeNode *root[27];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> n;
		root[i] = new TreeNode(n);

		cin >> l;
		if (l != '.') root[i]->left = new TreeNode(l);

		cin >> r;
		if (r != '.') root[i]->right = new TreeNode(r);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (root[i]->left != NULL) {
				if (root[i]->left->val == root[j]->val) {
					root[i]->left = root[j];
				}
			}
			if (root[i]->right != NULL) {
				if (root[i]->right->val == root[j]->val) {
					root[i]->right = root[j];
				}
			}
		}
	}

	preorder(root[0]);
	cout << "\n";
	inorder(root[0]);
	cout << "\n";
	postorder(root[0]);

	return 0;
}