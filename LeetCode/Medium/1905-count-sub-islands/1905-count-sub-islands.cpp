// class Solution {
// public:
//     int countSubIslands(vector<vector<int>>& grid1,
//                         vector<vector<int>>& grid2) {
//         int m = grid2.size(), n = grid2[0].size();
//         bool isSubIsland = true;
//         int ans = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid2[i][j] == 1) {
//                     isSubIsland = true;
//                     dfs(grid1, grid2, i, j, isSubIsland);
//                     //only increment ans if its a valid subisland else not
//                     if (isSubIsland)
//                         ans++;
//                 }
//             }
//         }
//         return ans;
//     }
//     void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,
//              int j, bool& isSubIsland) {
//         int m = grid2.size(), n = grid2[0].size();

//         if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0)
//             return;
//         grid2[i][j] = 0;

//         if (grid1[i][j] == 0) {
//             isSubIsland = false;
//         }

//         dfs(grid1, grid2, i + 1, j, isSubIsland);
//         dfs(grid1, grid2, i - 1, j, isSubIsland);
//         dfs(grid1, grid2, i, j + 1, isSubIsland);
//         dfs(grid1, grid2, i, j - 1, isSubIsland);
//     }
// };
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int m = grid2.size(), n = grid2[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j))
                        ans++;
                }
            }
        }
        return ans;
    }
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,
             int j) {
        int m = grid2.size(), n = grid2[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0)
            return true;
        grid2[i][j] = 0;

        bool down = dfs(grid1, grid2, i + 1, j);
        bool up = dfs(grid1, grid2, i - 1, j);
        bool right = dfs(grid1, grid2, i, j + 1);
        bool left = dfs(grid1, grid2, i, j - 1);
        return (grid1[i][j] == 1) && down && up && right && left;
    }
};