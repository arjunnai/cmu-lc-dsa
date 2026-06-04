class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int l = 0, max_len = 0;
        unordered_set<int> ust;
        for (int r = 0; r < s.size(); r++) {
            while (ust.contains(s[r])) {
                ust.erase(s[l]);
                l++;
            }
            ust.insert(s[r]);
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};