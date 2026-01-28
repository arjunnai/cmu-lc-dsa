class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {
        vector<vector<int>> res = grid;
        dfs(grid, row, col, grid[row][col]);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] < 0) {
                    if (i == 0 || j == 0 || i == grid.size() - 1 ||
                        j == grid[0].size() - 1) {
                        res[i][j] = color;
                    } else if (grid[i - 1][j] >= 0 || grid[i][j - 1] >= 0 ||
                               grid[i + 1][j] >= 0 || grid[i][j + 1] >= 0) {
                        res[i][j] = color;
                    }
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int target) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] != target) {
            return;
        }
        grid[i][j] = -1;
        dfs(grid, i + 1, j, target);
        dfs(grid, i - 1, j, target);
        dfs(grid, i, j + 1, target);
        dfs(grid, i, j - 1, target);
    }
};