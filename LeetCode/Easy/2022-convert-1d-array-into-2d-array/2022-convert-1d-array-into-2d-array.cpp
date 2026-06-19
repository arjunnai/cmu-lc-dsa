class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != (size_t)m * n) return {};
        vector<vector<int>> res;
        for (int row = 0; row < m; row++) {
            vector<int> currrow;
            for (int col = 0; col < n; col++) {
                currrow.push_back(original[row * n + col]);
            }
            res.push_back(currrow);
        }
        return res;
    }
};