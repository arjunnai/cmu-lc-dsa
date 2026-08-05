class Solution {
public:
    int n;
    int t[1000][1000];
    string longestPalindrome(string s) {
        n = s.size();
        memset(t, -1, n*sizeof(int));
        int bestStart = 0, bestLen = 1;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (isPali(l, r, s) && r - l + 1 > bestLen) {
                    bestStart = l;
                    bestLen = r - l + 1;
                }
            }
        }
        return s.substr(bestStart, bestLen);
    }
    bool isPali(int l, int r, string& s) {
        if (l >= r)
            return true;
        if (t[l][r] != -1)
            return t[l][r];
        if (s[l] != s[r]) {
            return false;
        }
        return t[l][r] = isPali(l + 1, r - 1, s);
    }
};