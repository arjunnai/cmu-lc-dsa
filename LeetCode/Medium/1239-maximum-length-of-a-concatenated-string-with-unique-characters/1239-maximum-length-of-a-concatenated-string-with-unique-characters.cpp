class Solution {
public:
    int maxSize = 0;

    int maxLength(vector<string>& arr) {
        dfs(arr, 0, arr.size(), "");
        return maxSize;
    }

    void dfs(vector<string>& arr, int i, int n, string curr) {
        if (is_unique(curr) == false)
            return;
        if (i == n) {
            if (curr.size() > maxSize) {
                int currSize = curr.size();
                maxSize = max(maxSize, currSize);
            }
            return;
        }
        dfs(arr, i + 1, n, curr + arr[i]);
        dfs(arr, i + 1, n, curr);
    }
    bool is_unique(string& str) {
        int n = str.size();
        // ump stores the count of all the characters in string
        vector<int> ump(26, 0);
        for (int i = 0; i < n; i++) {
            ump[str[i] - 'a']++;
            // if we find duplicate return false
            if (ump[str[i] - 'a'] > 1)
                return false;
        }
        return true;
    }
};