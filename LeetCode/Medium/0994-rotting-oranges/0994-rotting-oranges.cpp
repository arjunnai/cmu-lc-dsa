class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int m = grid.size(), n = grid[0].size(), mins = 0, fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    rotten.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!rotten.empty() && fresh > 0) {
            int rotlevelsize = rotten.size();
            for (int k = 0; k < rotlevelsize; k++) {
                auto [i, j] = rotten.front();
                rotten.pop();
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n ||
                        grid[ni][nj] != 1)
                        continue;
                    grid[ni][nj] = 2;
                    fresh--;
                    rotten.push({ni, nj});
                }
            }
            mins++;
        }
        return fresh == 0 ? mins : -1;
    }
};