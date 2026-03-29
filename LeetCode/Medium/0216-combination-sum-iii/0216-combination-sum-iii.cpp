class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(k, n, res, curr, 1);
        return res;
    }

    void dfs(int k, int n, vector<vector<int>>& res, vector<int>& curr,
             int index) {
        /// base case same target - 0 but also has to be k numbers only
        if (curr.size() == k) {
            if (n == 0)
                res.push_back(curr);
            return;
        }

        if (n < 0)
            return;

        for (int i = index; i <= 9; i++) {
            curr.push_back(i);
            dfs(k, n - i, res, curr, i + 1);
            curr.pop_back();
        }
    }
};