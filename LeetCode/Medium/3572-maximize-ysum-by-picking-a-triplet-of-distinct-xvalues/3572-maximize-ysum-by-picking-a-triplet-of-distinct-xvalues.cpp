class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size() - 1;
        vector<int> scores;
        unordered_map<int, int> ump;
        for (int i = 0; i <= n; i++) {
            ump[x[i]] = max(y[i], ump[x[i]]);
        }
        for (auto item : ump) {
            scores.push_back(item.second);
        }
        if (scores.size() < 3) {
            return -1;
        }
        sort(scores.begin(), scores.end(), greater<int>());

        return scores[0] + scores[1] + scores[2];
    }
};