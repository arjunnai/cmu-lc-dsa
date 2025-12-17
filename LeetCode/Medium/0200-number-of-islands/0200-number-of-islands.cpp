class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCtr = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    islandVisited(grid, i, j);
                    islandCtr++;
                }
            }
        }
        return islandCtr;
    }

    void islandVisited(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] != '1') {
            return;
        } else {
            grid[i][j] = '2';
            islandVisited(grid, i + 1, j);
            islandVisited(grid, i, j + 1);
            islandVisited(grid, i - 1, j);
            islandVisited(grid, i, j - 1);
        }
    }
};