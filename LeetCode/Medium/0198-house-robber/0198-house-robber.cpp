class Solution {
public:
    int n;
    int t[100];
    int dfs(int idx, vector<int>& nums) {
        if (idx >= n) {
            return 0;
        }
        if (t[idx] != -1)
            return t[idx];

        // rob
        int rob = nums[idx] + dfs(idx + 2, nums);

        // dont rob
        int dont = dfs(idx + 1, nums);
        return t[idx] = max(rob, dont);
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return dfs(0, nums);
    }
};