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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if root is null, return false direct
        if (root == nullptr) {
            return false;
        } else {
            return (isSame(root, subRoot) || isSubtree(root->left, subRoot) ||
                        isSubtree(root->right, subRoot));
        }
    }

    bool isSame(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p && q || !q && p) {
            return false;
        }
        return (p->val == q->val && isSame(p->left, q->left) &&
                isSame(p->right, q->right));
    }
};