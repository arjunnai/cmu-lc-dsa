class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictSet(wordDict.begin(), wordDict.end());
        vector<string> res;
        vector<string> currPath;
        dfs(0, dictSet, s, res, currPath);
        return res;
    }

    void dfs(int idx, unordered_set<string>& dictSet, string& s,
             vector<string>& res, vector<string>& currPath) {
        if (idx == s.size()) {
            string sent = "";
            for (int i = 0; i < currPath.size(); i++) {
                sent += currPath[i];
                if (i < currPath.size() - 1) {
                    sent += " ";
                }
            }
            res.push_back(sent);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            string slice = s.substr(idx, i - idx + 1);
            if (dictSet.contains(slice)) {
                currPath.push_back(slice);
                dfs(i + 1, dictSet, s, res, currPath);
                currPath.pop_back();
            }
        }
    }
};