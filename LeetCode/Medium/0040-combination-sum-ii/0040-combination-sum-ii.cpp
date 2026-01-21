class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        dfs(res, curr, candidates, target, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& curr,
             vector<int>& candidates, int target, int i) {
        // success
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        // failure
        if (i == candidates.size() || target < 0) {
            return;
        }
        curr.push_back(candidates[i]);
        // include
        dfs(res, curr, candidates, (target - candidates[i]), i + 1);
        curr.pop_back();
        // while loop to skip index if there are duplicates
        while (i + 1 < candidates.size() &&
               candidates[i] == candidates[i + 1]) {
            i++;
        }
        dfs(res, curr, candidates, target, i + 1);
    }
};