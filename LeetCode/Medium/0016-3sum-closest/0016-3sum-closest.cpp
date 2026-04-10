class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), smallestDiff = INT_MAX;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                // targetdiff = target - sum of triplet
                int targetDiff = target - nums[i] - nums[left] - nums[right];
                if (targetDiff == 0) {
                    return target;
                }
                if (abs(targetDiff) < abs(smallestDiff)) {
                    smallestDiff = targetDiff;
                }
                if (targetDiff > 0) {
                    left++; // triplet sum is too small , need to increase the
                            // sum
                } else {
                    right--; // triplet sum is too larget, need to decrease it
                }
            }
        }
        return target - smallestDiff;
    }
};