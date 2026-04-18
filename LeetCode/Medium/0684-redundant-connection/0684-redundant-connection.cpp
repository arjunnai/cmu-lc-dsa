class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // // create adjacency list
        // vector<int> adj[n + 1];
        // for (int i = 0; i < n; i++) {
        //     adj[edges[i][0]].push_back(edges[i][1]);
        //     adj[edges[i][1]].push_back(edges[i][0]);
        //     vector<bool> visited(n + 1, false);
        //     if (dfs(edges[i][0], -1, adj, visited)) {
        //         return edges[i];
        //     }
        // }
        // return {};
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            vector<bool> visited(n + 1, false);
            if (dfs(u, v, adj, visited)) {
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }

    // bool dfs(int source, int parent, vector<int> adj[], vector<bool>&
    // visited) {
    //     visited[source] = true;
    //     for (auto& adjnode : adj[source]) {
    //         if (!visited[adjnode]) {
    //             if (dfs(adjnode, source, adj, visited))
    //                 return true;

    //         } else if (adjnode != parent)
    //             return true;
    //     }
    //     return false;
    // }
    bool dfs(int source, int target, vector<vector<int>>& adj,
             vector<bool>& visited) {
        if (source == target)
            return true;
        visited[source] = true;

        for (int neighbor : adj[source]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, target, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};