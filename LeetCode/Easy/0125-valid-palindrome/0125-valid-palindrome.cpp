class Solution {
public:
    bool isPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false; // Found a mismatch
            }
            l++;
            r--;
        }
        return true;
    }
};