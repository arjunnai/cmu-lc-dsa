# Count Subarrays Template

## Overview

**Best for:** Counting how many subarrays satisfy a condition (e.g., product < K)

**Problems:** LeetCode 713 (Subarray Product Less Than K)

**Logic:** The number of valid subarrays ending at `right` is exactly `right - left + 1`.

## Implementation

```cpp
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0; // Edge case for product < 1

    int n = nums.size();
    int left = 0;
    long long currentProduct = 1;
    int count = 0;

    for (int right = 0; right < n; right++) {
        // 1. Add Right
        currentProduct *= nums[right];

        // 2. Shrink Left (While condition is BROKEN)
        while (currentProduct >= k) {
            currentProduct /= nums[left];
            left++;
        }

        // 3. Count
        // All subarrays ending at 'right' and starting >= 'left' are valid
        count += (right - left + 1);
    }

    return count;
}
```