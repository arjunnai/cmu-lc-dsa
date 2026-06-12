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
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return neg ? INT_MIN : INT_MAX;
            }
            res = res * 10 + digit;
            i++;
        }
        return neg ? -res : res;
    }
};