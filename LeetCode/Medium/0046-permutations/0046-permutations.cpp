class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> curr;
        dfs(nums, res, used, curr);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<bool>& used,
             vector<int>& curr) {
        // base case if curr.size and nums size is same
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        // loop similar to combination
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true)
                continue;
            used[i] = true;
            curr.push_back(nums[i]);
            dfs(nums, res, used, curr);
            curr.pop_back();
            used[i] = false;
        }
    }
};