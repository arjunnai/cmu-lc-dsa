class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int moves = 0, rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            dfs(grid, i, 0);        // left
            dfs(grid, i, cols - 1); // right
        }

        for (int j = 0; j < cols; j++) {
            dfs(grid, 0, j);        // top
            dfs(grid, rows - 1, j); // bottom
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    moves++;
                }
            }
        }
        return moves;
    }
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 0;
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};