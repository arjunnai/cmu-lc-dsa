class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i < numRows; i++) {
            vector<int> r(row + 1, 1);
            long long val = 1;
            for (int j = 1; j < row; j++) {
                val = val * (row - j + 1) / j;
                r[j] = val;
            }
            ans.push_back(r);
        }
        return ans;
    }
};