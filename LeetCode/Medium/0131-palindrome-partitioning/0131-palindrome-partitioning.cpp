class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(s, 0, ans, curr);
        return ans;
    }
    bool isPali(string& s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void dfs(string& s, int idx, vector<vector<string>>& ans,
             vector<string>& curr) {
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPali(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                dfs(s, i + 1, ans, curr);
                curr.pop_back();
            }
        }
    }
};