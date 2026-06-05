class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                swap(nums[i], nums[l]);
                l++;
            }
        }
        return nums;
    }
};