class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, area = 0, rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    area = 0;
                    dfs(grid, area, i, j);
                }
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
    void dfs(vector<vector<int>>& grid, int& area, int i, int j) {
        int rows = grid.size(), cols = grid[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != 1) {
            return;
        }
        area++;
        grid[i][j] = 0;
        dfs(grid, area, i + 1, j);
        dfs(grid, area, i, j + 1);
        dfs(grid, area, i - 1, j);
        dfs(grid, area, i, j - 1);
    }
};