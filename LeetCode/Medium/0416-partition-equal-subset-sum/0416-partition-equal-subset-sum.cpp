class Solution {
public:
int t[201][10001];
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        memset(t, -1, sizeof(t));
        if (dfs(nums, target, 0))
            return true;
        return false;
    }
    bool dfs(vector<int>& nums, int target, int idx) {
        if (target == 0)
            return true;
        if (idx >= nums.size())
            return false;
if (t[idx][target] != -1) return t[idx][target];
        // skip
        if (dfs(nums, target, idx + 1))
            return t[idx][target]= true;
        // take
        if (target - nums[idx] >= 0) {
            if (dfs(nums, target - nums[idx], idx + 1))
                return t[idx][target] = true;
        }
        return t[idx][target] = false;
    }
};