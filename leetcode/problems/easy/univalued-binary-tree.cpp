/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    set<int> st;
public:
    void treeTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
       st.insert(root->val);
       isUnivalTree(root->left);
        isUnivalTree(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        treeTraversal(root);
        if(st.size() == 1) {
            return true;
        }
        return false;
    }
};
