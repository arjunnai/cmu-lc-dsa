#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops",          \
                     "no-stack-protector")
#pragma GCC target(                                                            \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (n == 1)
            return vector<int>{0};
        // nodes for adjacency list
        vector<vector<int>> graph(n);
        // count degree of nodes
        vector<int> degree(n, 0);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;
        //push all leaf nodes into queue
        for (int i = 0; i < degree.size(); i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int nodes = n;
        //iteratively update nodes by removeing leaf nodes (peeling onion)
        while (nodes > 2) {
            int size = q.size();
            nodes -= size;
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                for (auto& it : graph[curr]) {
                    //update degree of adj nodes of leaf nodes
                    degree[it]--;
                    //push node if its leaf node
                    if (degree[it] == 1) {
                        q.push(it);
                    }
                }
            }
        }
        // push root nodes to anser array
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};