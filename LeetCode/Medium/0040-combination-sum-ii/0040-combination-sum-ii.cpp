class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(candidates, target, ans, curr, 0);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans,
             vector<int>& curr, int i) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        } else if (i == candidates.size() || target < 0)
            return;
        // // include
        // curr.push_back(candidates[i]);
        // dfs(candidates, target - candidates[i], ans, curr, i + 1);
        // curr.pop_back();

        // // skip candidates[i]
        // int next = i + 1;
        // while (next < candidates.size() && candidates[next] == candidates[i])
        // {
        //     next++;
        // }
        // dfs(candidates, target, ans, curr, next);

        for (int j = i; j < candidates.size() && candidates[j] <= target; j++) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            curr.push_back(candidates[j]);
            dfs(candidates, target - candidates[j], ans, curr, j + 1);
            curr.pop_back();
        }
    }
};