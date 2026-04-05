class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string currIP = "";
        dfs(0, 0, currIP, res, s);
        return res;
    }
    void dfs(int idx, int dots, string& currIP, vector<string>& res,
             string& s) {
        // base case good - basically 4 dots and if its end of string
        if (dots == 4 && idx == s.size()) {
            res.push_back(currIP.substr(0, currIP.size() - 1));
            return;
        }
        // base case bad - if greater than 4 dots there's no point
        if (dots > 4)
            return;

        for (int j = idx; j < min(idx + 3, (int)s.size()); j++) {
            // this is to do 1 slice or 2 slice or 3 character slice
            string slice = s.substr(idx, j - idx + 1);
            if (stoi(slice) < 256 && (idx == j || s[idx] != '0')) {
                int len = currIP.size();
                currIP += slice + ".";
                dfs(j + 1, dots + 1, currIP, res, s);
                currIP.resize(len);
            }
        }
    }
};