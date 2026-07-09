class Solution {
public:
    typedef pair<int, int> P;
    vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0, mins = 0;
        queue<P> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
            return 0;
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                P curr = q.front();
                q.pop();
                int i = curr.first, j = curr.second;
                for (auto& d : dirs) {
                    int ni = i + d.first, nj = j + d.second;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                        continue;
                    if (grid[ni][nj] != 1)
                        continue;
                    grid[ni][nj] = 2;
                    q.push({ni, nj});
                    fresh--;
                }
            }
            mins++;
        }
        return fresh == 0 ? mins - 1 : -1;
    }
};