class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0, maxArea = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int& area) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] != 1) {
            return;
        }
        grid[i][j] = '*';
        area++;
        dfs(grid, i + 1, j, area);
        dfs(grid, i - 1, j, area);
        dfs(grid, i, j - 1, area);
        dfs(grid, i, j + 1, area);
    }
};