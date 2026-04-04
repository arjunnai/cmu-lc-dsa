class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, n, "", res);
        return res;
    }
    void dfs(int o, int c, string curr, vector<string>& res){
        if(o == c && o == 0 && c == 0){
            res.push_back(curr);
            return;
        }
        if(o > 0){
            dfs(o-1, c, curr+"(", res);
        }
        if(o < c){
            dfs(o, c-1, curr+")", res);
        }
    }
};