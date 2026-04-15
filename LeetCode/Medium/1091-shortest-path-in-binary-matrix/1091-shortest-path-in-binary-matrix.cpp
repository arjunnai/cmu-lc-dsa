class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        queue<pair<pair<int, int>, int>> q;
        grid[0][0] = 1;
        q.push({{0, 0}, 1});
        while (!q.empty()) {
            pair<pair<int, int>, int> curr = q.front();
            q.pop();

            if (curr.first.first == n - 1 && curr.first.second == n - 1) {
                return curr.second;
            }
            int dRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
            for (int i = 0; i <= 7; i++) {
                int nr = curr.first.first + dRow[i];
                int nc = curr.first.second + dCol[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                    grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    q.push({{nr, nc}, curr.second + 1});
                }
            }
        }
        return -1;
    }
};