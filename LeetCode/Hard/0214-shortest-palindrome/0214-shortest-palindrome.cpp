class Solution {
public:
    string shortestPalindrome(string s) {
        long long prefix = 0;
        long long suffix = 0;
        const long long base = 101;
        const long long mod = 1e9 + 7;
        int lastidx = -1;
        long long power = 1;
        for (int i = 0; i < s.size(); i++) {
            int ch = (s[i] - 'a' + 1);
            prefix = (prefix * base) % mod;
            prefix = (prefix + ch) % mod;
            suffix = (suffix + ch * power) % mod;
            power = (power * base) % mod;

            if (prefix == suffix) {
                lastidx = i;
            }
        }
        string res = s.substr(lastidx + 1);
        reverse(res.begin(), res.end());
        return res + s;
    }
};