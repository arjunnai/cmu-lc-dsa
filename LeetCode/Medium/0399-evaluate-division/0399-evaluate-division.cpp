class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        vector<double> res;

        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v, val});       // u->v
            adj[v].push_back({u, 1.0 / val}); // v->u
        }
        for (int i = 0; i < queries.size(); i++) {
            string u = queries[i][0];
            string v = queries[i][1];
            if (adj.find(u) == adj.end() || adj.find(v) == adj.end()) {
                res.push_back(-1);
                continue;
            }
            unordered_set<string> visited;
            res.push_back(dfs(adj, u, v, 1.0, visited));
        }
        return res;
    }

    double dfs(unordered_map<string, vector<pair<string, double>>>& adj,
               string curr, string target, double product,
               unordered_set<string>& visited) {
        if (curr == target)
            return product;

        visited.insert(curr);
        for (auto& [neighbor, weight] : adj[curr]) {
            if (visited.count(neighbor))
                continue;
            double result =
                dfs(adj, neighbor, target, product * weight, visited);
            if (result != -1.0)
                return result;
        }
        return -1.0;
    }
};