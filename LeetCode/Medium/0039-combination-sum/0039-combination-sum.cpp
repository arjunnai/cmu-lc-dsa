class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(candidates, target, curr, ans, 0);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, vector<int>& curr,
             vector<vector<int>>& ans, int idx) {
        // dfs either include candidates[idx] or dont include it
        if (target == 0) {
            ans.push_back(curr);
            return;
        } else if (idx == candidates.size() || target < 0) {
            return;
        }
        curr.push_back(candidates[idx]);
        dfs(candidates, target - candidates[idx], curr, ans, idx);
        // backtrack
        curr.pop_back();
        dfs(candidates, target, curr, ans, idx + 1);
    }
};