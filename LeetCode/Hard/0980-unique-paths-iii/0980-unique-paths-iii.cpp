class Solution {
public:
    int m;
    int n;
    int zeros;
    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        zeros = 0;
        int result = 0;
        int startx = 0, starty = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    zeros++;
                } else if (grid[i][j] == 1) {
                    startx = i;
                    starty = j;
                }
            }
        }

        return dfs(startx, starty, grid);
    }

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1) {
            return 0;
        }
        if (grid[i][j] == 2)
            return zeros == 0 ? 1 : 0;

        int temp = grid[i][j];
        grid[i][j] = -1;
        if (temp == 0)
            zeros--;

        int total = 0;
        for (auto& d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            total += dfs(ni, nj, grid);
        }
        grid[i][j] = temp;
        if (temp == 0)
            zeros++;
        return total;
    }
};