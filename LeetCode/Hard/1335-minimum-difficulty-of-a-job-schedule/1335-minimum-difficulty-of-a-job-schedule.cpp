class Solution {
public:
    int t[301][11];
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        memset(t, -1, sizeof(t));
        if (n < d)
            return -1;
        return dfs(jd, n, 0, d);
    }
    int dfs(vector<int>& jd, int n, int idx, int d) {
        // if only 1 day left, do all work and find max
        if (d == 1) {
            int maxD = jd[idx];
            for (int i = idx; i < n; i++) {
                maxD = max(maxD, jd[i]);
            }
            return maxD;
        }
        if (t[idx][d] != -1)
            return t[idx][d];
        // recursion
        int bestRes = INT_MAX, res = 0;
        int maxD = jd[idx];

        // n - d cuz if days are 2 and 4 jobs last day won't have any job
        for (int i = idx; i <= n - d; i++) {
            maxD = max(maxD, jd[i]);
            res = maxD + dfs(jd, n, i + 1, d - 1);
            bestRes = min(bestRes, res);
        }
        return t[idx][d] = bestRes;
    }
};