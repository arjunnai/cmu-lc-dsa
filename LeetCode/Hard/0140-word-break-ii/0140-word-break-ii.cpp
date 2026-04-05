class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // convert vector to a set so we have o(1) lookiup
        unordered_set<string> dictSet(wordDict.begin(), wordDict.end());
        vector<string> res;
        vector<string> currPath;
        dfs(s, dictSet, res, currPath, 0);
        return res;
    }

    void dfs(string& s, unordered_set<string>& dictSet, vector<string>& res,
             vector<string>& currPath, int idx) {
        // if scanner reaches end of string stop
        if (idx == s.size()) {
            // cant directly push currpath to res since both are jsut
            // vector<strings>
            string sentence = "";
            for (int i = 0; i < currPath.size(); i++) {
                sentence += currPath[i];
                if (i < currPath.size() - 1) {
                    sentence += " ";
                }
            }
            res.push_back(sentence);
            return;
        }
    //usual backtracking, check if slice is present in the dict, if it is add it to currpath, then dfs downwards then backtrack
        for (int j = idx; j < s.size(); j++) {
            string slice = s.substr(idx, j - idx + 1);
            if (dictSet.contains(slice)) {
                currPath.push_back(slice);
                dfs(s, dictSet, res, currPath, j + 1);
                currPath.pop_back();
            }
        }
    }
};