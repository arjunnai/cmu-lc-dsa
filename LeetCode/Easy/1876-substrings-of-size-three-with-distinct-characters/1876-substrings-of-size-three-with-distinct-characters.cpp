class Solution {
public:
    int countGoodSubstrings(string s) {
        int winlen = 3, count = 0;
        unordered_map<char, int> freq;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            if (i >= winlen) {
                freq[s[i - winlen]]--;
                if (freq[s[i - winlen]] == 0)
                    freq.erase(s[i - winlen]);
            }
            if (i >= winlen - 1 && freq.size() == winlen) {
                count++;
            }
        }

        return count;
    }
};