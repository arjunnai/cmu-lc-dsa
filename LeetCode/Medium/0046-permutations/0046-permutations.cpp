class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        dfs(res, curr, used, nums);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& curr, vector<bool>& used,
             vector<int>& nums) {
        // base case
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) {
                continue;
            }
            used[i] = true;
            curr.push_back(nums[i]);
            dfs(res, curr, used, nums);
            used[i] = false;
            curr.pop_back();
        }
    }
};