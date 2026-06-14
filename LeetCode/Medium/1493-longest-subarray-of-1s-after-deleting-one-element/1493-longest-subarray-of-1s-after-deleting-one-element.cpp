class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxlen = 0, start = 0, zero = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                start = zero + 1;
                zero = i;
            }
            maxlen = max(maxlen, i - start);
        }
        return maxlen;
    }
};