/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        pair<int, bool> result = dfs_helper(root);
        return result.second;
    }
    pair<int, bool> dfs_helper(TreeNode* root) {
        if (root == nullptr) {
            return {0, true};
        }
        pair<int, bool> leftResult = dfs_helper(root->left);
        pair<int, bool> rightResult = dfs_helper(root->right);
        int hi = 1 + max (leftResult.first, rightResult.first);
        bool bal = leftResult.second && rightResult.second && (abs(leftResult.first - rightResult.first) <= 1);
        // cout << "Node " << root->val << " received Left height=" << leftResult.first
        //      << ", Right height=" << rightResult.first << endl;
        return {hi, bal};
    }
};