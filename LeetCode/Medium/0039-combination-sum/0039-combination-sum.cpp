class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // dfs 2 options
        //  1 - include candidates[i], add num to curr, target - candidates[i],
        //  dfs(i), pop 2 - exclude candidates[i], curr unchanged, target
        //  unchanged, dfs(i+1)
        vector<vector<int>> res;
        vector<int> curr;
        dfs(res, curr, candidates, target, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& curr,
             vector<int>& candidates, int target, int i) {
        if (target == 0) { // success
            res.push_back(curr);
            return;
        } else if (i == candidates.size() || target < 0) { // failure
            return;
        }
        curr.push_back(candidates[i]);
        dfs(res, curr, candidates, (target - candidates[i]), i);
        curr.pop_back();
        dfs(res, curr, candidates, target, i + 1);
    }
};