class Solution {
public:
    int n;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums, 0, curr, res);
        return res;
    }
    void backtrack(vector<int>& nums, int idx, vector<int>& curr,
                   vector<vector<int>>& res) {
        if (curr.size() >= 2) {
            res.push_back(curr);
        }
        unordered_set<int> st;
        for (int i = idx; i < n; i++) {
            if ((curr.empty() || nums[i] >= curr.back()) &&
                !st.contains(nums[i])) {
                curr.push_back(nums[i]);
                backtrack(nums, i + 1, curr, res);
                curr.pop_back();

                st.insert(nums[i]);
            }
        }
    }
};