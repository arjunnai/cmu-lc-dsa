class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            // int idx = (((i+nums[i])%n) + n)%n;
            // res[i] = nums[idx];
            int idx = 0;
            if (nums[i] > 0) {
                idx = (i + nums[i]) % n;
                res[i] = nums[idx];

            } else if (nums[i] < 0) {
                idx = ((i + nums[i]) % n + n) % n;
                res[i] = nums[idx];

            } else {
                res[i] == nums[i];
            }
        }
        return res;
    }
};