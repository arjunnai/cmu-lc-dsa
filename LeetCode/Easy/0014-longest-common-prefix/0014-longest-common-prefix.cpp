class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
         string ans = "";
        int i = 0;
        string s1 = strs[0], s2 = strs[strs.size() - 1];
        while (i < strs[0].length()) {
            if (strs[0][i] == strs[strs.size() - 1][i]) {
                ans += strs[0][i];
            } else
                break;
            i++;
        }
        return ans;
    }
};