class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        dfs(s, ans, temp, 0);
        return ans;
    }

    void dfs(string& s, vector<vector<string>>& ans, vector<string>& temp,
             int idx) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (pali(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                dfs(s, ans, temp, i + 1);
                temp.pop_back();
            }
        }
    }

    bool pali(string s, int index, int i) {
        int l = index, r = i;
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};