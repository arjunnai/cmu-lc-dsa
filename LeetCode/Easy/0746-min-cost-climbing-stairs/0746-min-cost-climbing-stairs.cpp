class Solution {
public:
    int t[1000];
    int dfs(int i, vector<int>& cost) {
        if (i >= cost.size())
            return 0;
        if (t[i] != -1)
            return t[i];
        return t[i] = cost[i] + min(dfs(i + 1, cost), dfs(i + 2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(t, -1, sizeof(t));
        int zCost = dfs(0, cost);
        int fCost = dfs(1, cost);
        return min(zCost, fCost);
    }
};