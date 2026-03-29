class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, res, subset, 0);
        return res;

        // for (int i = 0; i < nums.size(); i++) {
        //     int resSize = res.size();
        //     for (int j = 0; j < resSize; j++) {
        //         vector<int> copy = res[j];
        //         copy.push_back(nums[i]);
        //         res.push_back(copy);
        //     }
        // }
        // return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset,
             int idx) {
        if (idx == nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        dfs(nums, res, subset, idx + 1);
        subset.pop_back();
        dfs(nums, res, subset, idx + 1);
    }
};