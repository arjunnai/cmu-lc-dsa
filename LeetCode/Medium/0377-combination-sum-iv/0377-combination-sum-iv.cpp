class Solution {
public:
    int n;
    int t[201][1001];
    int combinationSum4(vector<int>& nums, int target) {
        int res = 0;
        memset(t, -1, sizeof(t));
        n = nums.size();
        return dfs(0, nums, target);
    }
    int dfs(int idx, vector<int>& nums, int target) {
        if (target == 0)
            return 1;
        if (idx >= n || target < 0)
            return 0;
        if (t[idx][target] != -1)
            return t[idx][target];

                   int take_idx = dfs(0, nums, target - nums[idx]);
        int reject_idx = dfs(idx + 1, nums, target);
        return t[idx][target] = take_idx + reject_idx;
    }
};
