# Frequency Map Template (Anagrams, Pattern Matching)

## Overview

**Best for:** LeetCode 438 (Find All Anagrams), 567 (Permutation in String)

**Key Difference:** State is tracked using `vector<int>` (size 26) instead of a single integer.

**Time Complexity:** O(N) (Comparison of size 26 vectors is constant time O(1))

## Implementation

```cpp
#include <vector>
#include <string>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    int ns = s.size();
    int np = p.size();
    if (ns < np) return {};

    vector<int> result;
    
    // Frequency arrays for 'p' and the current window in 's'
    vector<int> pCount(26, 0);
    vector<int> sCount(26, 0);

    // Build reference map for 'p'
    for (char c : p) pCount[c - 'a']++;

    // --- PHASE 1: Initialize first window in 's' ---
    for (int i = 0; i < np; i++) {
        sCount[s[i] - 'a']++;
    }

    // Check the very first window
    if (sCount == pCount) result.push_back(0);

    // --- PHASE 2: Slide the window ---
    for (int i = np; i < ns; i++) {
        // 1. Add Right (New character enters)
        sCount[s[i] - 'a']++;

        // 2. Drop Left (Old character leaves)
        sCount[s[i - np] - 'a']--;

        // 3. Compare Maps
        // In C++, vectors can be compared directly with ==
        if (sCount == pCount) {
            result.push_back(i - np + 1);
        }
    }

    return result;
}
```