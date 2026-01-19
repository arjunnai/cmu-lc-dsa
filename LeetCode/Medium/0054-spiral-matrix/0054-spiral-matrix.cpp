class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1, left = 0,
            right = matrix[0].size() - 1;
        vector<int> res;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                // left -> right
                res.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                // top -> bottom on right col
                res.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    // right -> left on bottom row
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    // left -> right on left col
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};