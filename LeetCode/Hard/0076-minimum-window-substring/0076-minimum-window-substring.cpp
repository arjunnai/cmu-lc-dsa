class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        unordered_map<char, int> windowMap;
        int minLen = INT_MAX;
        int minStart = 0;
        int have = 0, left = 0;
        // phase 1 - where we check if t substring is in s
        for (int i = 0; i < t.size(); i++) {
            tMap[t[i]]++;
        }
        int need = tMap.size();
        for (int right = 0; right < s.size(); right++) {
            windowMap[s[right]]++;
            if (tMap.contains(s[right]) &&
                (tMap[s[right]] == windowMap[s[right]])) {
                have++;
                // phase 2 - we need to shrink to find min window substr
                while (have == need) {
                    if ((right - left + 1) < minLen) {
                        minLen = right - left + 1;
                        minStart = left;
                    }
                    windowMap[s[left]]--;
                    if (tMap.count(s[left]) &&
                        windowMap[s[left]] < tMap[s[left]]) {
                        have--;
                    }
                    left++;                    
                }
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};