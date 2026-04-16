class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(s, ans, curr, 0);
        return ans;
    }
    void dfs(string s, vector<vector<string>>& ans, vector<string>& curr,
             int start) {
        if (start == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));
                dfs(s, ans, curr, end + 1);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};