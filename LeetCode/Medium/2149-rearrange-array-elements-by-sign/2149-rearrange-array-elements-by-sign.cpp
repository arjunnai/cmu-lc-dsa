class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ansArr(nums.size(), 0);
        int posIdx = 0, negIdx = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ansArr[posIdx] = nums[i];
                posIdx += 2;
            } else {
                ansArr[negIdx] = nums[i];
                negIdx += 2;
            }
        }
        return ansArr;
    }
};