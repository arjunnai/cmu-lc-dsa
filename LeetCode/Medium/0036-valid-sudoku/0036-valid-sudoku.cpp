class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rowSt;
        unordered_set<int> colSt;
        unordered_set<int> boxSt;

        for (int i = 0; i < 9; i++) {
            rowSt.clear();
            colSt.clear();
            boxSt.clear();
            for (int j = 0; j < 9; j++) {
                char row = board[i][j];
                char col = board[j][i];
                if (row != '.') {
                    if (rowSt.count(row)) {
                        return false;
                    } else {
                        rowSt.insert(row);
                    }
                }
                if (col != '.') {
                    if (colSt.count(col)) {
                        return false;
                    } else {
                        colSt.insert(col);
                    }
                }
                int rowIdx = 3 * (i / 3) + j / 3;
                int colIdx = 3 * (i % 3) + j % 3;

                if (board[rowIdx][colIdx] != '.') {
                    if (boxSt.count(board[rowIdx][colIdx])) {
                        return false;
                    } else {
                        boxSt.insert(board[rowIdx][colIdx]);
                    }
                }
            }
        }
        return true;
    }
};