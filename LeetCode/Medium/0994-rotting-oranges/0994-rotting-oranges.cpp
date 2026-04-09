class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int fresh = 0, minutes = 0, rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        // fresh>0 - because if there are no fresh oranges we don't need to
        // incremebt minutes
        while (!rotten.empty() && fresh > 0) {
            // standard bfs template
            int size = rotten.size();
            while (size--) {
                // get coordinates for first item in queue in terms or {r,c}
                pair<int, int> curr = rotten.front();
                // pop it so we don't double count it
                rotten.pop();
                int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (auto& dir : dirs) {
                    int ni = curr.first + dir[0];
                    int nj = curr.second + dir[1];
                    if (ni >= 0 && nj >= 0 && ni < rows && nj < cols &&
                        grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        rotten.push({ni, nj});
                        fresh--;
                    }
                }
            }
            minutes++; // minutes increase after each full level has been
                       // processed
        }
        //if fresh > 0, then some oranges still survived so return -1 else return minutes
        return (fresh > 0) ? -1 : minutes;
    }
};