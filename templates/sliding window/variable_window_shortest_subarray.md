# Shortest Subarray Template

## Overview

**Best for:** Finding the minimum window size that meets a threshold

**Problems:** LeetCode 209 (Min Size Subarray Sum)

**Logic:**

- Expand right.
- While the window is valid (e.g., sum >= target), update `minLen` and shrink left to try and make it smaller.

## Implementation

```cpp
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int currentSum = 0;
    int minLen = INT_MAX;

    for (int right = 0; right < n; right++) {
        // 1. Add Right
        currentSum += nums[right];

        // 2. Shrink Left (While condition is VALID)
        // We try to make the window smaller while keeping sum >= target
        while (currentSum >= target) {
            minLen = min(minLen, right - left + 1);
            
            // Remove left element
            currentSum -= nums[left];
            left++;
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}
```