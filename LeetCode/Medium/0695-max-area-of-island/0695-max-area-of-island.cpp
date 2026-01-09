class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int area = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    area = 0;
                    search(grid, i, j, area);
                }
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
    void search(vector<vector<int>>& grid, int i, int j, int& area) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] != 1) {
            return;
        }

        area++;
        grid[i][j] = '*';
        search(grid, i + 1, j, area);
        search(grid, i, j + 1, area);
        search(grid, i - 1, j, area);
        search(grid, i, j - 1, area);
    }
};