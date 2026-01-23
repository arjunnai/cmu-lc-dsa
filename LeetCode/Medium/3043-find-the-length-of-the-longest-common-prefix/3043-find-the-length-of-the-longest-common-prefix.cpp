class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // calc prefix and add to hashset for arr1
        unordered_set<int> prefix;
        int len = 0, maxLen = 0;
        for (int a1 : arr1) {
            while (a1 > 0) {
                prefix.insert(a1);
                a1 = a1 / 10;
            }
        }

        // calc prefix for arr2 and check if already exists in hashset
        for (int a2 : arr2) {
            while (a2 > 0) {
                if (prefix.contains(a2)) {
                    len = to_string(a2).length();
                    maxLen = max(maxLen, len);
                    break;
                }
                a2 = a2 / 10;
            }
        }
        return maxLen;
    }
};