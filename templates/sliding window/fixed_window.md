# C++ Fixed Sliding Window Templates

This repository contains standard templates for **Fixed Size Sliding Window** problems (where the window size `k` is constant).

## 1. General Accumulation Template (Sum, Average, Count)
**Best for:** `643` (Max Average), `1343` (Avg >= Threshold), `1456` (Max Vowels).
**Time Complexity:** $O(N)$
**Space Complexity:** $O(1)$

```cpp
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// Generic solver for Array inputs
int solveFixedWindowArray(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) return 0; // Handle edge case

    // --- PHASE 1: Initialize the first window ---
    // Use 'long long' if sums can exceed integer limits
    long long currentSum = 0; 
    for (int i = 0; i < k; i++) {
        currentSum += nums[i];
    }

    // Initialize answer with the first window's result
    long long maxSum = currentSum;

    // --- PHASE 2: Slide the window ---
    // Start from index 'k'. 
    // We add nums[i] (Right enters) 
    // We remove nums[i-k] (Left leaves)
    for (int i = k; i < n; i++) {
        // 1. Add Right
        currentSum += nums[i];
        
        // 2. Drop Left
        currentSum -= nums[i - k];
        
        // 3. Update Answer
        maxSum = max(maxSum, currentSum);
    }

    return (int)maxSum; // Cast back if needed
}