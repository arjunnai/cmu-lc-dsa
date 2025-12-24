class Solution {
public:
    int reverse(int x) {
        int ans = 0, digit = 0;
        while (x != 0) {
            digit = x % 10;
            x = x / 10;
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
            // if (ans * 10 > INT_MAX || ans * 10 < INT_MIN) {
                return 0;
            }
            ans = ans * 10 + digit;
        }
        return ans;
    }
};