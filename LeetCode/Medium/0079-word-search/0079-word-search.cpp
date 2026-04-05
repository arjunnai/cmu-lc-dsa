class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == word[0]) {
                    if (dfs(board, word, row, col, 0))
                        return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int row, int col,
             int idx) {
        // base case : reach end of the word
        if (idx == word.size()) {
            return true;
        }
        // base case bad : out of bounds, lettter doesn't match target or *
        // already visited
        if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0 ||
            board[row][col] != word[idx]) {
            return false;
        }

        // visited hack - mark position as *
        char tempVisited = board[row][col];
        board[row][col] = '*';

        // create bool, call dfs on 4 directions - up, down, left, right, if any
        // true - variable is true
        bool found = dfs(board, word, row - 1, col, idx + 1) ||
                     dfs(board, word, row + 1, col, idx + 1) ||
                     dfs(board, word, row, col - 1, idx + 1) ||
                     dfs(board, word, row, col + 1, idx + 1);

        // backtrack
        board[row][col] = tempVisited;

        // return bool variable
        return found;
    }
};