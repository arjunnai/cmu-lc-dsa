class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int size = nums.size();
        int validCount = 0;
        for (int l = 0; l < size; ++l) {
            long long even = 0, odd = 0;
            for (int r = l; r < size; ++r) {
                if (nums[r] % 2 == 0) {
                    ++even;
                } else {
                    ++odd;
                }
                if (odd > 0 && even * b <= odd * a) {
                    ++validCount;
                }
            }
        }
        return validCount;
    }
};