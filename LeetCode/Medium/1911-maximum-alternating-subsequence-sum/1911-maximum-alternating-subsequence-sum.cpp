class Solution {
public:
    long long t[1000000][2];
    // hack in this problem is whenever we skip, flag stays the same (if its +
    // stays as + else -) and when we take it flips
    long long maxAlternatingSum(vector<int>& nums) {
        bool flag = true;
        memset(t, -1, sizeof(t));
        return dfs(nums, 0, flag);
    }
    long long dfs(vector<int>& nums, int idx, bool flag) {
        if (idx == nums.size()) {
            return 0;
        }
        if (t[idx][flag] != -1)
            return t[idx][flag];
        // skip
        long long skip = dfs(nums, idx + 1, flag);
        int val = nums[idx];
        if (!flag) {
            val = -val;
        }
        // take
        long long take = dfs(nums, idx + 1, !flag) + val;

        return t[idx][flag] = max(skip, take);
    }
};