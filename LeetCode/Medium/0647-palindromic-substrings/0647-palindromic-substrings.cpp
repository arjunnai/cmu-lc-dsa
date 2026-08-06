class Solution {
public:
    int t[1001][1001];
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        for (int i = 0; i < n; i++)
            memset(t[i], -1, n * sizeof(int));
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (isPali(l, r, s)) {
                    count++;
                }
            }
        }
        return count;
    }
    bool isPali(int l, int r, string& s) {
        if (l >= r)
            return true;
        if (t[l][r] != -1)
            return t[l][r];
        if (s[l] != s[r])
            return false;
        return t[l][r] = isPali(l + 1, r - 1, s);
    }
};