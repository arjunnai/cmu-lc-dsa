class Solution {
public:
    int myAtoi(string s) {
        int res = 0, i = 0, n = s.size();
        bool neg = false;
        // whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        // chck for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            neg = (s[i] == '-');
            i++;
        }

        // digits and overflow
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            // check overflow before updating res
            // int = 2147483647 - ends in 7, so /10 gives you 214748364 we do *10 so it will overflow  if its equal we check if digit coming in is 7 or lower then its safe else overflow
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return neg ? INT_MIN : INT_MAX;
            }
            res = res * 10 + digit;
            i++;
        }
        return neg ? -res : res;
    }
};