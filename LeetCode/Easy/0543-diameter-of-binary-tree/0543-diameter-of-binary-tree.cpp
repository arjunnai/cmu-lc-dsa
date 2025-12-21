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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> res = dfs(root);
        return {res.second};
    }
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        pair<int, int> lResult = dfs(root->left);
        pair<int, int> rResult = dfs(root->right);
        int maxDepth = 1 + max(lResult.first, rResult.first);
        int diameter = (lResult.first + rResult.first);
        int maxDiameter = max({diameter, lResult.second, rResult.second});

        return {maxDepth, maxDiameter};

        
    }
};