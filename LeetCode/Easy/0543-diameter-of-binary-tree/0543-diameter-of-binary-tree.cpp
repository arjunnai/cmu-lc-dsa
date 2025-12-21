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
    int maxD = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxD;
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int lD = maxDepth(root->left);
        int rD = maxDepth(root->right);
        maxD = max(maxD, lD + rD);
        return (1+max(lD, rD));
    }
};