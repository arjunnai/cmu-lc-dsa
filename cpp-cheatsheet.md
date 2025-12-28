```markdown
# C++ Algorithms Cheat Sheet (Sliding Window & Hashing)

## 1. Essential Headers & Constants
```cpp
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> // for min, max, sort
#include <climits>   // for INT_MAX, INT_MIN

int maxVal = INT_MAX; // 2147483647
int minVal = INT_MIN; // -2147483648

```

## 2. Strings

**Key Concept:** Strings are mutable in C++.

```cpp
string s = "hello";

// Access
char c = s[0]; // 'h'
int len = s.size(); // or s.length()

// Substring - CRITICAL: Takes (Start Index, LENGTH)
// NOT (Start, End) like Python/Java
string sub = s.substr(0, 2); // "he" (Start at 0, take 2 chars)
string sub2 = s.substr(3);   // "lo" (Start at 3, take rest)

// Char to Integer Mapping (0-25)
int index = s[i] - 'a'; // 'a'->0, 'b'->1 ... 'z'->25

```

## 3. Vectors (Dynamic Arrays)

```cpp
// Initialization
vector<int> nums; 
vector<int> counts(26, 0); // Size 26, all filled with 0

// Operations
nums.push_back(5);    // Add to end
nums.pop_back();      // Remove last
int size = nums.size();

```

## 4. Hash Maps (Unordered Map)

**Key Concept:** O(1) average time complexity.

```cpp
unordered_map<char, int> countMap;

// Add / Update
countMap['a']++;      // Increment count for 'a'
countMap['b'] = 5;    // Set directly

// Check Existence
// Option A: .count() returns 1 if exists, 0 if not
if (countMap.count('a')) { ... } 

// Option B: .contains() (C++20 only)
if (countMap.contains('a')) { ... }

// Remove
countMap.erase('a');

// Iterate
for (auto const& [key, val] : countMap) {
    // key is char, val is int
}

```

## 5. The "Frequency Array" Optimization

Use this instead of a HashMap when keys are small and fixed (e.g., only lowercase English letters).
It is faster (O(1) vs HashMap overhead).

```cpp
// Instead of unordered_map<char, int>
vector<int> map(26, 0);

// Add
map[s[i] - 'a']++;

// Remove
map[s[i] - 'a']--;

// Compare two frequency maps directly
if (map1 == map2) return true; // Works instantly in C++

```

## 6. Sliding Window Template (Dynamic Size)

**Mental Model:** Expand `right` to find a valid window, then shrink `left` to optimize it.

```cpp
int minStart = 0;
int minLen = INT_MAX;
int left = 0;

for (int right = 0; right < s.size(); right++) {
    // 1. Add right character to current window
    windowMap[s[right]]++;
    
    // 2. Update status (Did we satisfy a requirement?)
    if ( ... ) { have++; }

    // 3. Shrink Left (While window is valid)
    while (have == need) {
        // A. Update Result (Snapshot)
        if ((right - left + 1) < minLen) {
            minLen = right - left + 1;
            minStart = left; // SAVE "left", don't use it later
        }

        // B. Remove left character
        windowMap[s[left]]--;
        
        // C. Update status (Did we break the window?)
        if ( ... ) { have--; }

        // D. Move left pointer
        left++;
    }
}

// Return
return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);

```
