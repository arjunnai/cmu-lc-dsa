class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ump;
        int left = 0;
        int curr_length = 0, max_length = 0;
        for (int right = 0; right < s.size(); right++) {
            if (ump.count(s[right])) {
                left = max(left, ump[s[right]] + 1);
            }
            ump[s[right]] = right;
            curr_length = right - left + 1;
            max_length = max(curr_length, max_length);
        }
        return max_length;
    }
};