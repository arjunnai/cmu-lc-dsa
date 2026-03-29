class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(res, curr, n, k, 1);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& curr, int n, int k,
             int index) {
        if (curr.size() >= k) {
            res.push_back(curr);
            return;
        }
        for (int i = index; i <= n-(k-curr.size())+1; i++) {
            curr.push_back(i);
            //including i
            dfs(res, curr, n, k, i+1);
            curr.pop_back();
        }
    }
};