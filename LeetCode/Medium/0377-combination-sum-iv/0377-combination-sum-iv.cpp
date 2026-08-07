class Solution {
public:
    int n;
    int t[1001];
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return dfs(nums, target);
    }
    int dfs(vector<int>& nums, int target) {
        if (target == 0) {
            return 1;
        }
        if (target < 0) { // overshot
            return 0;
        }
        if(t[target]!=-1)return t[target];
        int remain = 0;
        for (int i = 0; i < n; i++) {
            remain += dfs(nums, target - nums[i]);
        }
        return t[target] = remain;
    }
};