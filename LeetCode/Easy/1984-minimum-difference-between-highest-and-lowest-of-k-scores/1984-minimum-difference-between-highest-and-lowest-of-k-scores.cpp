class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, diff = 0, minDiff = INT_MAX;
        for (int r = k - 1; r < nums.size(); r++) {
            l = r - k + 1;
            diff = nums[r] - nums[l];
            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }
};