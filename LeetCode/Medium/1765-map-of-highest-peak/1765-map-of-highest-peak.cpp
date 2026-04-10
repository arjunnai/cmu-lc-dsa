class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size(), cols = isWater[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto& dir : dirs) {
                int ni = curr.first + dir[0];
                int nj = curr.second + dir[1];
                if (ni >= 0 && nj >= 0 && ni < rows && nj < cols) {
                    if (ans[ni][nj] == -1) {
                        // neighbours height is curr cell height + 1
                        ans[ni][nj] = ans[curr.first][curr.second] + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }

        return ans;
    }
};

// all heights +ve
// all water cells ie isWater[i][j] == 1, height = 0
// adjacent in all directions max height diff of 1.