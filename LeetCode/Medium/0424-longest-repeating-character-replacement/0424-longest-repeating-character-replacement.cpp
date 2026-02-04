class Solution {
public:
    int characterReplacement(string s, int k) {
        // unordered_map<char, int> ump;
        vector<int> count(26, 0);
        int max_freq = 0;
        int ans = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            // ump[s[r]]++;
            count[s[r] - 'A']++;
            // max_freq = max(max_freq, ump[s[r]]);
            max_freq = max(max_freq, count[s[r]-'A']);
            if ((r - l + 1) - max_freq > k) {
                // ump[s[l]]--;
                count[s[l]-'A']--;
                l++;
            }
            ans = max(ans, (r - l + 1));
        }
        return ans;
    }
};