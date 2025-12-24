class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1, left = 0,
            right = matrix[0].size() - 1;
        vector<int> answer;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) {
                // move first row on top from left to right
                answer.push_back(matrix[top][j]);
            }
            // top or 0th row is done so next row now.
            top++;
            for (int j = top; j <= bottom; j++) {
                // move from top to bottom on right most row
                answer.push_back(matrix[j][right]);
            }
            // right most col is done so next col now.
            right--;
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    answer.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int j = bottom; j >= top; j--) {
                    answer.push_back(matrix[j][left]);
                }
                left++;
            }
        }
        return answer;
    }
};