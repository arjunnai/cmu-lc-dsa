class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxSum = 0, sum = 0, l = 0, r = nums.size() - 1;
        while (l < r) {
            sum = nums[l] + nums[r];
            maxSum = max(sum, maxSum);
            l++;
            r--;
        }
        return maxSum;
    }
};