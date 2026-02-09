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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        dfs(root, nodes);
        return build(nodes, 0, nodes.size() - 1);
    }
    void dfs(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, nodes);
        nodes.push_back(root);
        dfs(root->right, nodes);
    }
    TreeNode* build(vector<TreeNode*>& nodes, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* node = nodes[mid];
        node->left = build(nodes, start, mid - 1);
        node->right = build(nodes, mid + 1, end);
        return node;
    }
};