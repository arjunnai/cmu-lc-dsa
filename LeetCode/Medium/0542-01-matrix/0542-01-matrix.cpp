class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int rows = mat.size();
        int cols = mat[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    mat[i][j] = INT_MAX;
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            vector<pair<int, int>> check = {
                {r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
            for (auto [row, col] : check) {
                if (row >= 0 && row < rows && col >= 0 && col < cols &&
                    mat[row][col] > mat[r][c] + 1) {
                    mat[row][col] = mat[r][c] + 1;
                    q.push({row, col});
                }
            }
        }
        return mat;
    }
};