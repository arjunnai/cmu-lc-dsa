class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minutes = 0, freshOranges = 0;
        queue<pair<int, int>> orangeQ;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    orangeQ.push({i, j});
                }
                if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        while (!orangeQ.empty() && freshOranges > 0) {
            int oSize = orangeQ.size();
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};
            for (int i = 0; i < oSize; i++) {
                pair<int, int> curr = orangeQ.front();
                orangeQ.pop();
                int r = curr.first;
                int c = curr.second;
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        orangeQ.push({nr, nc});
                        freshOranges--;
                    }
                }
            }
            minutes++;
        }

        return freshOranges == 0 ? minutes : -1;
    }
};