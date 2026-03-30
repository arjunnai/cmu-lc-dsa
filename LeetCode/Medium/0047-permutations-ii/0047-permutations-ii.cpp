class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> curr;
        dfs(nums, res, used, curr);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<bool>& used,
             vector<int>& curr) {
        // same base case as permutatioin
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // !used[i-1] is there so that if theres 1, 1 then we want to use second 1 if first 1 is already in curr list , if its false, it means we finished expooring everything starting with first 1 and now our loop has moved sideways to second 1
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
                    // do permutation recursion
                    if (used[i] == true) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            dfs(nums, res, used, curr);
            curr.pop_back();
            used[i] = false;
        }
    }
};