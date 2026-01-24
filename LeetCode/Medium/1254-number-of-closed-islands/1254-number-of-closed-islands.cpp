class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int validIsland = 0;
        // phase 1 cleanup on edges
        for (int j = 0; j < cols; j++) {
            // top row
            if (grid[0][j] == 0) {
                dfs(grid, 0, j);
            }
            // bottom row
            if (grid[rows - 1][j] == 0) {
                dfs(grid, rows - 1, j);
            }
        }

        for (int i = 0; i < rows; i++) {
            // left col
            if (grid[i][0] == 0) {
                dfs(grid, i, 0);
            }
            // right col
            if (grid[i][cols - 1] == 0) {
                dfs(grid, i, cols - 1);
            }
        }

        // phase 2 - normal dfs like we did for island problem
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j);
                    validIsland++;
                }
            }
        }
        return validIsland;
    }
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int row = grid.size();
        int cols = grid[0].size();
        if (i < 0 || i >= row || j < 0 || j >= cols || grid[i][j] != 0) {
            return;
        }
        grid[i][j] = 1;
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};