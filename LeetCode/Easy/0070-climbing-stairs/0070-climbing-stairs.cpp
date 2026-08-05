class Solution {
public:
    int t[46];
    int dfs(int n) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1; // we got 1 way to cover stairs;

        if (t[n] != -1)
            return t[n];
        int oneStep = dfs(n - 1);
        int twoStep = dfs(n - 2);
        return t[n] = oneStep + twoStep;
    }

    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return dfs(n);
    }
};