class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        dfs(candidates, target, res, curr, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res,
             vector<int>& curr, int index) {
        // base case same - target == 0 then success
        if (target == 0) {
            res.push_back(curr);
            return;
        } else if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size() && candidates[i] <= target;
             i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            curr.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], res, curr, i + 1);
            curr.pop_back();
        }
    }
};