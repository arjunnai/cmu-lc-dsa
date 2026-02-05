class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> want(p.size());
        unordered_map<char, int> window(p.size());
        for (auto& iter : p) {
            want[iter]++;
        }
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            window[s[r]]++;
            if (r - l + 1 > p.size()) {
                // remove it from window
                window[s[l]]--;
                if (window[s[l]] == 0) {
                    window.erase(s[l]);
                }
                // increment l to check next
                l++;
            }
            if (window == want) {
                res.push_back(l);
            }
        }
        return res;
    }
};