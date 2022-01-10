#include <vector>

using namespace std;

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
	vector<int> nodes;

	void inOrderTraversal(TreeNode* node) {
		if (node == NULL) {
			return;
		}
		inOrderTraversal(node->left);
		nodes.push_back(node->val);
		inOrderTraversal(node->right);
	}
	bool isValidBST(TreeNode* root) {
		inOrderTraversal(root);
		for (int i = 1; i < nodes.size(); i++) {
			if (nodes[i] <= nodes[i - 1]) {
				return false;
			}
		}
		return true;
	}
};