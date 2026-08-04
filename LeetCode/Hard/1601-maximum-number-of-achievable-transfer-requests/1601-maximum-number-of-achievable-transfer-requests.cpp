class Solution {
public:
    int res = INT_MIN;
    int reqSize;
    int maximumRequests(int n, vector<vector<int>>& requests) {
        reqSize = requests.size();
        vector<int> buildings(n, 0);
        dfs(0, 0, buildings, requests);
        return res;
    }
    void dfs(int idx, int count, vector<int>& buildings,
             vector<vector<int>>& requests) {
        if (idx >= reqSize) {
            bool zero = true;
            for (auto& it : buildings) {
                if (it != 0) {
                    zero = false;
                    break;
                }
            }
            if (zero) {
                res = max(res, count);
            }
            return;
        }

        int from = requests[idx][0];
        int to = requests[idx][1];

        buildings[from]--;
        buildings[to]++;
        dfs(idx + 1, count + 1, buildings, requests);

        // not take it
        buildings[from]++;
        buildings[to]--;
        // count doesn't increase if we are not choosing it
        dfs(idx + 1, count, buildings, requests);
    }
};