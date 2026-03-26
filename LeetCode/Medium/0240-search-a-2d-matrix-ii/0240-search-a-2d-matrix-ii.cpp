class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        //start from bottom row, first element
        int row = n - 1, col = 0;
        while (row >= 0 && col < m) {
            if (target == matrix[row][col]) {
                return true;
            } else if (target > matrix[row][col]) {
                col += 1;
            } else {
                row -= 1;
            }
        }
        return false;
    }
};