class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        // border
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j, 'S');
            }
            if (board[rows - 1][j] == 'O') {
                dfs(board, rows - 1, j, 'S');
            }
        }
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, 'S');
            }
            if (board[i][cols - 1] == 'O') {
                dfs(board, i, cols - 1, 'S');
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        // for (const auto& row : board) {
        //     for (char c : row) {
        //         cout << c << " ";
        //     }
        //     cout << endl; // Move to next line after each row
        // }
    }
    void dfs(vector<vector<char>>& board, int i, int j, int target) {
        int rows = board.size(), cols = board[0].size();
        if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != 'O') {
            return;
        }
        board[i][j] = target;
        dfs(board, i, j + 1, target);
        dfs(board, i + 1, j, target);
        dfs(board, i, j - 1, target);
        dfs(board, i - 1, j, target);
    }
};