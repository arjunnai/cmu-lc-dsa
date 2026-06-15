class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> psum(nums.size() + 1);
        psum[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            psum[i] = psum[i - 1] + nums[i - 1];
        }
        unordered_map<int, int> seen;
        int count = 0;
        for (int i = 0; i < psum.size(); i++) {
            int rem = ((psum[i] % k) + k) % k;
            count += seen[rem];
            seen[rem]++;
        }
        return count;
    }
};