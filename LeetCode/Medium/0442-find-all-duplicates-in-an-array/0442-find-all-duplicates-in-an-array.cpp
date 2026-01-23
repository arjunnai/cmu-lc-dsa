class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        // flip already seen number index to negative, since its from 1 -> n, if
        // number is 2, idx will be 1
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                res.push_back(abs(nums[i]));
            } else {
                nums[idx] = -nums[idx];
            }
        }
        return res;
    }
};