class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                //we either check if after skipping l, rest is a palindrome or after skipping r, rest is a palindrome
                return isPali(s, l + 1, r) || isPali(s, l, r - 1);
            }
        }
        return true;
    }
    bool isPali(string s, int l, int r) {
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
};