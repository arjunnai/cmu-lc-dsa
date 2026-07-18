class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }
        // if all water or all land
        if (q.empty() || q.size() == n * n)
            return -1;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int dist = -1;
        while (!q.empty()) {
            int qs = q.size();
            for (int c = 0; c < qs; c++) {
                auto [i, j] = q.front();
                q.pop();
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= n)
                        continue;
                    if (grid[ni][nj] != 0)
                        continue;
                    grid[ni][nj] = 2;
                    q.push({ni, nj});
                }
            }
            dist++;
        }
        return dist;
    }
};