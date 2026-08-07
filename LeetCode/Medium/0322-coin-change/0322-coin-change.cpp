class Solution {
public:
    int t[13][10001];
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(t, -1, sizeof(t));
        int res = dfs(0, coins, amount);
        return res == INT_MAX ? -1 : res;
    }

    int dfs(int idx, vector<int>& coins, int amount) {

        if (amount == 0)
            return 0;
        if (idx >= coins.size() || amount < 0)
            return INT_MAX;
        if (t[idx][amount] != -1)
            return t[idx][amount];
        // skip coin
        int skip = dfs(idx + 1, coins, amount);
        // take coin
        int take = INT_MAX;
        if (amount - coins[idx] >= 0) {
            int sub = dfs(idx, coins, amount - coins[idx]);
            if (sub != INT_MAX)
                take = 1 + sub;
        }
        return t[idx][amount] = min(skip, take);
    }
};