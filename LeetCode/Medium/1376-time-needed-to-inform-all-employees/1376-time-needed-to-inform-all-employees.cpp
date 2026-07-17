class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i); // manager -> emp
            }
        }
        return dfs(headID, adj, informTime);
    }
    int dfs(int head, vector<vector<int>>& adj, vector<int>& informTime) {
        if (adj[head].empty())
            return 0;
        int time = 0;
        for (int child : adj[head]) {
            time = max(time, dfs(child, adj, informTime));
        }
        return informTime[head] + time;
    }
};