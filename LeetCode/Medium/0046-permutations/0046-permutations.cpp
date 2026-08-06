class Solution {
public:
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size(); vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(n, false);
        dfs(0, nums, curr, res, used);
        return res;
    }
    void dfs(int idx, vector<int>& nums, vector<int>& curr,
             vector<vector<int>>& res, vector<bool>& used) {
        if (idx == n) {
            res.push_back(curr);
            return;
        }
        // use
        for (int i = 0; i < n; i++) {
            if (used[i] == true)
                continue;
            used[i] = true;
            curr.push_back(nums[i]);
            dfs(idx + 1, nums, curr, res, used);
            curr.pop_back();
            used[i] = false;
        }

    }
};