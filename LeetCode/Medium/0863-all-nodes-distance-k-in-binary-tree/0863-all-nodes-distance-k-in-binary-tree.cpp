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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        findParents(root, nullptr, parentMap);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);
        int currentDist = 0;

        // bfs loop
        while (!q.empty() && currentDist < k) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                vector<TreeNode*> neighbors = {curr->left, curr->right,
                                               parentMap[curr]};
                for (TreeNode* next : neighbors) {
                    if (next && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
                // if (curr->left && !visited[curr->left]) {
                //     q.push(curr->left);
                //     visited[curr->left] = true;
                // }
                // if (curr->right && !visited[curr->right]) {
                //     q.push(curr->right);
                //     visited[curr->right] = true;
                // }
                // if (parentMap[curr] && !visited[parentMap[curr]]) {
                //     q.push(parentMap[curr]);
                //     visited[parentMap[curr]] = true;
                // }
            }
            currentDist++;
        }

        // whatever is in q is not exactly k distance away
        vector<int> res;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }

    void findParents(TreeNode* curr, TreeNode* parent,
                     unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (!curr)
            return;
        if (parent) {
            parentMap[curr] = parent;
        }
        findParents(curr->left, curr, parentMap);
        findParents(curr->right, curr, parentMap);
    }
};