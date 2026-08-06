class Solution {
public:
    int t[2501][2501];
    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return dfs(0, -1, nums);
    }
    int dfs(int idx, int prevIdx, vector<int>& nums) {
        // base case
        if (idx >= nums.size()) {
            return 0;
        }
        if (t[idx][prevIdx + 1] != -1)
            return t[idx][prevIdx + 1];
        // skip
        int skip = dfs(idx + 1, prevIdx, nums);
        // take
        int take = 0;
        if (prevIdx == -1 || nums[idx] > nums[prevIdx])
            take = 1 + dfs(idx + 1, idx, nums);
        return t[idx][prevIdx + 1] = max(skip, take);
    }
};