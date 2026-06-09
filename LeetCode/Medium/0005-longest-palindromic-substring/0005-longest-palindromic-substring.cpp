class Solution {
public:
    string longestPalindrome(string s) {
        //     int l = 0, r = s.size() - 1;
        //     string longest = "";
        //     // while (l < r) {
        //     //     if (isPali(s, l, r) && (r - l + 1) > longest.size()) {
        //     //         longest = s.substr(l, r - i + 1);
        //     //     }
        //     //     l++;
        //     //     r--;
        //     // }
        //     for (int i = 0; i < s.size(); i++) {
        //         for (int j = i; j < s.size(); j++) {
        //             if (isPali(s, i, j) && (j - i + 1) > longest.size()) {
        //                 longest = s.substr(i, j - i + 1);
        //             }
        //         }
        //     }
        //     return longest;
        // }
        // bool isPali(string s, int l, int r) {
        //     while (l < r) {
        //         if (s[l] != s[r]) {
        //             return false;
        //         }
        //         l++;
        //         r--;
        //     }
        //     return true;
        // }
        // o(n3) above

        if (s.size() < 1)
            return "";
        int start = 0, maxLen = 0;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
            }
            return r - l - 1;
        };

        for (int i = 0; i < s.size(); i++) {
            int len1 = expand(i, i);
            int len2 = expand(i, i + 1);
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
            return s.substr(start, maxLen);
        }
    };