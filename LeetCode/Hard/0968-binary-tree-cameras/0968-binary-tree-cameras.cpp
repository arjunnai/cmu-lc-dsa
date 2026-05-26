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
    //0 - we need help from parents, when we are leaf or all children are covered but the current node has no camera
    //1 - we put a camera in current node, we return this to parenets so they know they're covered
    //2 - covered by a children having a camera
    int cameras = 0;
    int solver(TreeNode* node) {
        if (!node) {
            return 2;
        }
        int left = solver(node->left);
        int right = solver(node->right);

        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        } else if (left == 1 || right == 1) {
            return 2;
        } else {
            return 0;
        }
    }

public:
    int minCameraCover(TreeNode* root) {
        int camerastate = solver(root);
        if (camerastate == 0)
            cameras++;
        return cameras;
    }
};