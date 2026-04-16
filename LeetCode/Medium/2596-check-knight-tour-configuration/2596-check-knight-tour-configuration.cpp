class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        // vector to store index and value
        vector<pair<int, int>> pos(n * n);

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                pos[grid[r][c]] = {r, c};
            }
        }
        // knight has to start from top left
        if (pos[0].first != 0 || pos[0].second != 0) {
            return false;
        }
        for (int i = 0; i < (n * n) - 1; i++) {
            int r1 = pos[i].first;
            int c1 = pos[i].second;
            int r2 = pos[i + 1].first;
            int c2 = pos[i + 1].second;

            int rowDiff = abs(r1 - r2);
            int colDiff = abs(c1 - c2);
            // valid knight move has a diff of 1 in one direction, 2 in the
            // other
            bool isValidMove = (rowDiff == 1 && colDiff == 2) ||
                               (rowDiff == 2 && colDiff == 1);

            if (!isValidMove) {
                return false;
            }
        }
        return true;
    }
};