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
        pair<int, bool> res = dfs(root);
        return res.second;
    }
    pair<int, bool> dfs(TreeNode* root) {
        if (!root)
            return {0, true};
        pair<int, bool> lr = dfs(root->left);
        pair<int, bool> rr = dfs(root->right);

        int height = 1 + max(lr.first, rr.first);
        bool balanced =
            lr.second && rr.second && (abs(lr.first - rr.first) <= 1);
        return {height, balanced};
    }
};