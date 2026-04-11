class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        unordered_map<int, vector<int>> adjGraph;
        for (auto& edge : edges) {
            int i = edge[0];
            int j = edge[1];
            adjGraph[i].push_back(j);
            adjGraph[j].push_back(i);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == destination) {
                return true;
            }
            for (int neighbour : adjGraph[node]) {
                if (visited[neighbour] == false) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};