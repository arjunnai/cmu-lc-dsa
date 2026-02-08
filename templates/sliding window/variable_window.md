# C++ Variable Sliding Window Templates

This repository contains templates for **Variable Size Sliding Window** problems.

## 1. Generic "Longest Subarray" Template
**Best for:** Finding the longest subarray/substring that satisfies a condition.
**Problems:** `159`, `487`, `904`, `1004`.
**Logic:**
1.  Expand `right`.
2.  If invalid, shrink `left` until valid.
3.  Update `max_len` *after* shrinking (when the window is guaranteed valid).

```cpp
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int left = 0;
    int maxLen = 0;
    
    // State variable (e.g., count of distinct chars, count of zeros)
    unordered_map<char, int> countMap; 
    
    for (int right = 0; right < n; right++) {
        // 1. Add Right (Expand window)
        char c = s[right];
        countMap[c]++;

        // 2. Shrink Left (While condition is broken)
        // Example condition: "More than 2 distinct characters"
        while (countMap.size() > 2) {
            char leftChar = s[left];
            countMap[leftChar]--;
            if (countMap[leftChar] == 0) {
                countMap.erase(leftChar);
            }
            left++;
        }

        // 3. Update Answer (Window is now valid)
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}