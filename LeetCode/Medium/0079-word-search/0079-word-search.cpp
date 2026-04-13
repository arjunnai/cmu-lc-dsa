class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int idx,
             vector<vector<int>>& visited) {
        // base case - outbound and inbound
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        if (visited[i][j] == 1 || board[i][j] != word[idx]) {
            return false;
        }
        if (idx == word.size() - 1) {
            return true;
        }
        visited[i][j] = 1;
        if (dfs(board, word, i - 1, j, idx + 1, visited) ||
            dfs(board, word, i + 1, j, idx + 1, visited) ||
            dfs(board, word, i, j - 1, idx + 1, visited) ||
            dfs(board, word, i, j + 1, idx + 1, visited)) {
            return true;
        }
        // backtrack
        visited[i][j] = 0;
        return false;
    }
};