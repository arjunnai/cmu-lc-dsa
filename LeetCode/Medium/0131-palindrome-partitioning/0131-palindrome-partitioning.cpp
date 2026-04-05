class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> currPath;
        dfs(0, currPath, res, s);
        return res;
    }

    void dfs(int idx, vector<string>& currPath, vector<vector<string>>& res,
             string& s) {
        // base case
        if (idx == s.size()) {
            res.push_back(currPath);
            return;
        }

        for (int j = idx; j < s.size(); j++) {
            if (isPalindrome(s, idx, j)) {
                // take the palindrome slice and add it to currrpath
                currPath.push_back(s.substr(idx, j - idx + 1));
                //move start index to j+1
                dfs(j + 1, currPath, res, s);
                //backtrack
                currPath.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int l, int h) {
        while (l < h) {
            if (s[l++] != s[h--])
                return false;
        }
        return true;
    }
};