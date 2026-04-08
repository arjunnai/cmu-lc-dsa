class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> finalMap;
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, cols - 1);
        }
        for (int j = 0; j < cols; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, rows - 1, j);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    finalMap.push_back({i, j});
                }
            }
        }
        return finalMap;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i,
             int j) {
        ocean[i][j] = true;
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto& dir : dirs) {
            int next_i = i + dir[0];
            int next_j = j + dir[1];
            // boundary check - if conditions are true and in bound
            if (next_i >= 0 && next_j >= 0 && next_i < heights.size() &&
                next_j < heights[0].size()) {
                // check if it has already been visited before and also the new
                // ones height is higher than last ones
                if (!ocean[next_i][next_j] &&
                    heights[next_i][next_j] >= heights[i][j]) {
                    dfs(heights, ocean, next_i, next_j);
                }
            }
        }
    }
};