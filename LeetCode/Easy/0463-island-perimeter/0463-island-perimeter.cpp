class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    peri += dfs(grid, i, j);
                }
            }
        }
        return peri;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        //if you look up see water or edge of map(edge case) we gotta add to perimeter same with right left down (which are edge case boundaries, if you look up and see land no need of boundary though)
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 0) {
            return 1; // water gives 1 to perimeter
        }
        if (grid[i][j] == -1) {
            return 0;
        }
        grid[i][j] = -1;

        return (dfs(grid, i + 1, j) + dfs(grid, i - 1, j) +
                dfs(grid, i, j + 1) + dfs(grid, i, j - 1));
    }
};