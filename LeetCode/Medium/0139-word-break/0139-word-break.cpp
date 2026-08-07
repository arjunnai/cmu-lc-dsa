class Solution {
public:
    int n;
    int t[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        n = s.size();
        memset(t, -1, sizeof(t));
        if (dfs(s, wordSet, 0))
            return true;
        return false;
    }
    bool dfs(string& s, unordered_set<string>& wordSet, int start) {
        if (start == n) {
            return true;
        }
        if (t[start] != -1)
            return t[start];
        for (int i = start + 1; i <= n; i++) {
            if (wordSet.contains(s.substr(start, i - start)) &&
                dfs(s, wordSet, i))
                return t[start] = true;
        }
        return t[start] = false;
    }
};
