class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int steps = 0, rows = grid.size(), cols = grid[0].size();
        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) {
            return -1;
        }
        grid[0][0] = 1;
        q.push({0, 0});
        steps++;
        while (!q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                auto [r, c] = q.front();
                q.pop();
                // check if we reached target
                if (r == rows - 1 && c == cols - 1) {
                    return steps;
                }

                int check[8][2] = {{r + 1, c},     {r, c + 1},
                                   {r - 1, c},     {r, c - 1},
                                   {r + 1, c - 1}, {r + 1, c + 1},
                                   {r - 1, c - 1}, {r - 1, c + 1}};
                for (auto& [i, j] : check) {
                    if (i >= 0 && j >= 0 && i < rows && j < cols &&
                        grid[i][j] == 0) {
                        grid[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};