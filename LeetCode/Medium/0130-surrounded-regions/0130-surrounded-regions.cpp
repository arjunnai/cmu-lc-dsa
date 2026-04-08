class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            dfs(board, i, 0);        // left border
            dfs(board, i, cols - 1); // right border
        }

        for (int j = 0; j < cols; j++) {
            dfs(board, 0, j);//top border
            dfs(board, rows - 1, j);//bottom border
        }

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols; j++){
                if(board[i][j] == 'O')board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O'; 
                    
                
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != 'O') {
            return;
        }
        board[i][j] = '#';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};