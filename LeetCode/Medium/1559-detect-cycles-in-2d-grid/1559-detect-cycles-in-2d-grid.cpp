class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j]) {
                    bool temp = dfs(grid, visited, i, j);
                    if (temp)
                        return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i,
             int j, int preI = -1, int preJ = -1) {
        if (i >= grid.size() || j >= grid[0].size())
            return false;
        if (visited[i][j])
            return true;
        visited[i][j] = true;
        bool temp1 = false, temp2 = false, temp3 = false, temp4 = false;
        if (j < grid[0].size() - 1 && grid[i][j] == grid[i][j + 1] &&
            (j + 1) != preJ)
            temp1 = dfs(grid, visited, i, j + 1, -1, j);
        if (i < grid.size() - 1 && grid[i][j] == grid[i + 1][j] &&
            (i + 1) != preI)
            temp2 = dfs(grid, visited, i + 1, j, i, -1);
        if (j > 0 && grid[i][j] == grid[i][j - 1] && (j - 1) != preJ)
            temp4 = dfs(grid, visited, i, j - 1, -1, j);
        if (i > 0 && grid[i][j] == grid[i - 1][j] && (i - 1) != preI)
            temp3 = dfs(grid, visited, i - 1, j, i, -1);
        return temp1 || temp2 || temp3 || temp4;
    }
};