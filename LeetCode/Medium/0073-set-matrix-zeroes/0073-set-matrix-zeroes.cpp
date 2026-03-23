class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<bool> rowdead(rows, false);
        vector<bool> coldead(cols, false);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    rowdead[i] = true;
                    coldead[j] = true;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rowdead[i] == true || coldead[j] == true) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};