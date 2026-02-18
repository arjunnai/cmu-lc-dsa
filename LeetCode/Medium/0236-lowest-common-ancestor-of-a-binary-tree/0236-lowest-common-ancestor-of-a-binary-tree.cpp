/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root == p || root == q)
            return root;
        TreeNode* lr = lowestCommonAncestor(root->left, p, q);
        TreeNode* rr = lowestCommonAncestor(root->right, p, q);
        if (lr && rr)
            return root;
        return (lr) ? lr : rr;
    }
};