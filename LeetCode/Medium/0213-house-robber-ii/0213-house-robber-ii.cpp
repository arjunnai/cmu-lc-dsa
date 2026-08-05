class Solution {
public:
    int t[100];
    int n;
    int dfs(int i, int j, vector<int>& nums) {
        if (i > j)
            return 0;
        if (t[i] != -1)
            return t[i];
        return t[i] =
                   max((nums[i] + dfs(i + 2, j, nums)), (dfs(i + 1, j, nums)));
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        if (n == 1)
            return nums[0];
        memset(t, -1, sizeof(t));
        int skipLast = dfs(0, n - 2, nums);
        memset(t, -1, sizeof(t));
        int skipFirst = dfs(1, n - 1, nums);
        return max(skipLast, skipFirst);
    }
};