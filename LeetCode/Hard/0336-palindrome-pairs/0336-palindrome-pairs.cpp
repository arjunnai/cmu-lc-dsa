class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        set<int> lengths;
        unordered_map<string, int> dict;
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            dict[words[i]] = i;
            lengths.insert(words[i].size());
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                int leftLen = j;
                int rightLen = words[i].size() - j;
                if (lengths.count(rightLen)) {
                    string left = words[i].substr(0, j);
                    string right = words[i].substr(j);

                    if (isPalindrome(left)) {
                        string target(right.rbegin(), right.rend());
                        if (dict.count(target) && dict[target] != i) {
                            ans.push_back({dict[target], i});
                        }
                    }
                }
                if (lengths.count(leftLen)) {
                    string left = words[i].substr(0, j);
                    string right = words[i].substr(j);

                    if (right.size() > 0 && isPalindrome(right)) {
                        string target(left.rbegin(), left.rend());
                        if (dict.count(target) && dict[target] != i) {
                            ans.push_back({i, dict[target]});
                        }
                    }
                }
            }
        }
        return ans;
    }
    bool isPalindrome(string& s) {
        int l = 0, r = s.size() - 1;
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