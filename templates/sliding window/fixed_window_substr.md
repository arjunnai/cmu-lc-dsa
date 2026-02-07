# Substring Set Template (Unique Substrings)

## Overview

**Best for:** LeetCode 1461 (Check If String Contains All Binary Codes)

**Logic:** Instead of tracking a sum, we insert the actual substring (or its hash) into a Set.

**Time Complexity:** O(N * K) because of string slicing/hashing

## Implementation

```cpp
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

bool hasAllCodes(string s, int k) {
    if (s.size() < k) return false;

    unordered_set<string> seen;
    
    // Loop through all possible substrings of length k
    // Note: This is O(N * K) because of string slicing/hashing
    for (int i = 0; i <= s.size() - k; i++) {
        // Extract substring of length k starting at i
        seen.insert(s.substr(i, k));
    }

    // Check if we found all 2^k possibilities
    return seen.size() == pow(2, k);
}
```