class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> ump;
        int left = 0, maxCount = 0, winLen = 0, maxLen = 0;
        for (int right = 0; right < s.size(); right++) {
            ump[s[right]]++;
            maxCount = max(maxCount, ump[s[right]]);
            winLen = right - left + 1;
            if (winLen - maxCount <= k) {
                maxLen++;
            } else {
                ump[s[left]]--;
                left++;
            }
        }
        return maxLen;
    }
};