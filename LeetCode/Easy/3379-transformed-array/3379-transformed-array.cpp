class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int n = nums.size();
        for(int i = 0 ; i < nums.size(); i++){
            int idx = (((i+nums[i])%n) + n)%n;
            res[i] = nums[idx];
        }
        return res;
    }
};