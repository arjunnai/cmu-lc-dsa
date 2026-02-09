class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        int count = 0;
        bool odd = false;
        for (char c : s) {
            freq[c]++;
        }
        for (auto& iter : freq) {
            if (iter.second % 2 == 0) {
                count += iter.second;
            }else{
                count += iter.second - 1;
                odd = true;
            }
        }
        if(odd){
            return count + 1;
        }
        return count;
    }
};