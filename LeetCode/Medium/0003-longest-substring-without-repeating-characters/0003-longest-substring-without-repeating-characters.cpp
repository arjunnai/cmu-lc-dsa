class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int> ump;
        while (right < s.length()) {
            if (ump.find(s[right]) == ump.end()) {
                ump[s[right]]++;
                maxLen = max(maxLen, (right-left+1));
                right++;
            }else{  
                ump.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};