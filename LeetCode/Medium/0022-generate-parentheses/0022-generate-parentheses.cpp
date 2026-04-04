class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        dfs(n, n, curr, res);
        return res;
    }
    void dfs(int o, int c, string& curr, vector<string>& res){
        if(o == 0 && c == 0){
            res.push_back(curr);
            return;
        }
        if(o > 0){
            //can either use push_back or directly call curr + "(" in the fucntion, if using push_back, have to pop_back also
            curr.push_back('(');
            dfs(o-1, c, curr, res);
            curr.pop_back();
        }
        if(o < c){
            curr.push_back(')');
            dfs(o, c-1, curr, res);
            curr.pop_back();
        }
    }
};