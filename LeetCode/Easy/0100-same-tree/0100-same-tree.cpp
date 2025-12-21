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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 3 checks
        // 1. both nullptr → same
        // 2. one nullptr other not → not same
        // 3. neither nullptr, values should be same (as in children should be
        // identical on sides)
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr && q != nullptr ||
                   p != nullptr && q == nullptr){
            return false;
        }
        
        return (p->val == q->val && isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right) );
    }
};