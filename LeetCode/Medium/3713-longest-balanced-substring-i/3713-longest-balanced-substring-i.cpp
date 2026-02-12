class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> freq;
            for (int j = i; j < s.size(); j++) {
                freq[s[j]]++;
                if (balance(freq, freq[s[j]])) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
    bool balance(unordered_map<char, int>& freq, int value) {
        for (auto iter : freq) {
            if (iter.second != value) {
                return false;
            }
        }
        return true;
    }
};