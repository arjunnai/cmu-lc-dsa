class Solution {
    bool check(vector<int>& track, string& s) {
        // self check
        vector<int> self(26, 0);
        for (auto i : s) {
            if (self[i - 'a'])
                return false;
            self[i - 'a'] = 1;
        }

        // track check
        for (auto i : s) {
            if (track[i - 'a'])
                return false;
        }
        return true;
    }
    void dfs(int& ans, int index, vector<int>& track, vector<string>& arr,
             int len) {

        // base case
        if (index >= arr.size()) {
            ans = max(ans, len);
            return;
        }
        // dfs begins - we need to check if we can take the string or not
        if (check(track, arr[index])) {
            // this means it came true and we have to either include or exclude
            // it include
            for (auto i : arr[index]) {
                track[i - 'a'] = 1;
            }
            dfs(ans, index + 1, track, arr, len + arr[index].size());

            // exclude
            for (auto i : arr[index]) {
                track[i - 'a'] = 0;
            }
            dfs(ans, index + 1, track, arr, len);
        } else {
            dfs(ans, index + 1, track, arr, len);
        }
    }

public:
    int maxLength(vector<string>& arr) {
        int ans = INT_MIN, index = 0;
        vector<int> track(26, 0);
        dfs(ans, index, track, arr, 0);
        return ans;
    }
};