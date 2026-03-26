class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int l = 0, r = (row * col) - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            //only trick here is this to find mid value in matrix
            int midV = matrix[mid / col][mid % col];
            if (target == midV) {
                return true;
            } else if (target > midV) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};