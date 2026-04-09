class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int rows = mat.size(), cols = mat[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = INT_MAX;
                }
            }
        }

        while (!q.empty()) {
            // standard bfs template
            pair<int, int> curr = q.front();
            int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            q.pop();
            for (auto& dir : dirs) {
                int ni = curr.first + dir[0];
                int nj = curr.second + dir[1];
                // edge cases
                if (ni >= 0 && nj >= 0 && ni < rows && nj < cols) {
                    // Only update if the current path is shorter than what's
                    // there
                    if (mat[ni][nj] > mat[curr.first][curr.second] + 1) {
                        mat[ni][nj] = mat[curr.first][curr.second] + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }

        return mat;
    }
};