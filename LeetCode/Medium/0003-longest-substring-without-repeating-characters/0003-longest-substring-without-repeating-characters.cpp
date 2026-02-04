class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, sLen = 0, maxSlen = 0;
        unordered_map<char, int> freq;
        for (int r = 0; r < s.size(); r++) {
            while (freq.contains(s[r])) {
                freq.erase(s[l]);
                l++;
            }
            freq[s[r]]++;
            sLen = r - l + 1;
            maxSlen = max(sLen, maxSlen);
        }
        return maxSlen;
    }
};