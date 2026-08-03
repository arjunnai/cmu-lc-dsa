class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n, result, nonObstacle;
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        nonObstacle = 0, result = 0;
        int startX = 0, startY = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    nonObstacle++;
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }
        nonObstacle += 1;
        int count = 0;
        backtrack(grid, count, startX, startY);
        return result;
    }
    void backtrack(vector<vector<int>>& grid, int count, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
            return;
        if (grid[i][j] == 2) {
            if (count == nonObstacle)
                result++;
            return;
        }
        grid[i][j] = -1;
        for (auto& d : dirs) {
            int newi = i + d[0];
            int newj = j + d[1];
            backtrack(grid, count + 1, newi, newj);
        }
        grid[i][j] = 0;
    }
};