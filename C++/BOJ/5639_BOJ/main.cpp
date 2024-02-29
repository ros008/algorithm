#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int num): val(num), left(NULL), right(NULL){}
};

void postorder(TreeNode* node) {
	if (node == NULL) return;

	postorder(node->left);
	postorder(node->right);
	cout << node->val << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int input;
	cin >> input;
	TreeNode *root = new TreeNode(input);

	while (cin >> input) {
		TreeNode *tmp = root;
		while (1) {
			if (input < tmp->val) {
				if (tmp->left == NULL) {
					tmp->left = new TreeNode(input);
					break;
				}
				else {
					tmp = tmp->left;
					continue;
				}
			}
			else if (input > tmp->val) {
				if (tmp->right == NULL) {
					tmp->right = new TreeNode(input);
					break;
				}
				else {
					tmp = tmp->right;
					continue;
				}
			}
		}
	}

	postorder(root);

	return 0;
}