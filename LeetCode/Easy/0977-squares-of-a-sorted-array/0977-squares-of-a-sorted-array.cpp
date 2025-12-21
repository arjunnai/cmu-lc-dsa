class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int index = nums.size() - 1;
        vector<int> result(nums.size());
        while (left <= right) {
            if ((nums[left] * nums[left]) > (nums[right] * nums[right])) {
                result[index] = nums[left] * nums[left];
                left++;
                index--;
            } else {
                result[index] = nums[right] * nums[right];
                right--;
                index--;
            }
        }
        return result;
    }
};