class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxres = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            // if (nums[r] == 1) {
            //     count++;
            //     maxres = max(maxres, count);
            // } else {
            //     count = 0;
            // }
            if (nums[r] != 1) {
                l = r + 1;
            }
            maxres = max(maxres, r - l + 1);
        }
        return maxres;
    }
};