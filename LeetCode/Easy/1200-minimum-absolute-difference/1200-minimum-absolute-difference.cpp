class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX, diff = 0;
        vector<vector<int>> res;
        for (int i = 1; i < arr.size(); i++) {
            diff = arr[i] - arr[i - 1];
            if (diff < minDiff) {
                minDiff = min(minDiff, diff);
                res.clear();
                res.push_back({arr[i - 1], arr[i] });
            } else if (diff == minDiff) {
                res.push_back({arr[i - 1],arr[i]});
            }
        }
        return res;
    }
};