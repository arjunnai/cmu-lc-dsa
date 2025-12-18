class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size() - 1;
        // vector<int> scores;
        unordered_map<int, int> ump;
        for (int i = 0; i <= n; i++) {
            ump[x[i]] = max(y[i], ump[x[i]]);
        }
        // for (auto item : ump) {
        //     scores.push_back(item.second);
        // }
        // if (scores.size() < 3) {
        //     return -1;
        // }
        // sort(scores.begin(), scores.end(), greater<int>());

        // return scores[0] + scores[1] + scores[2];
        priority_queue<int, vector<int>, greater<int>> scores;
        for (auto item : ump) {
            scores.push(item.second);
            if (scores.size() > 3) {
                scores.pop();
            }
        }
        if (scores.size() < 3) {
            return -1;
        } else {
            int sum = 0;
            while (!scores.empty()) {
                cout << scores.top();
                sum += scores.top();
                scores.pop();
            }

            return sum;
        }
    }
};