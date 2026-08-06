class Solution {
public:
    int t[1001][1001];
    bool pred(string& a, string& b) {
        int as = a.size(), bs = b.size();
        if (bs - as != 1)
            return false;
        int i = 0, j = 0;
        while (j < bs) {
            if (i < as && a[i] == b[j]) {
                i++;
                j++;
            } else if (a[i] != b[j]) {
                j++;
            }
        }
        return (i == as) ? true : false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        memset(t, -1, sizeof(t));
        return dfs(0, -1, words);
    }

    int dfs(int idx, int prevIdx, vector<string>& words) {
        if (idx >= words.size())
            return 0;
        if (t[idx][prevIdx + 1] != -1)
            return t[idx][prevIdx + 1];
        // no take
        int skip = dfs(idx + 1, prevIdx, words);
        // take
        int take = 0;
        if (prevIdx == -1 || pred(words[prevIdx], words[idx])) {
            take = 1 + dfs(idx + 1, idx, words);
        }
        return t[idx][prevIdx + 1] = max(skip, take);
    }
};