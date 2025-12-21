class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 3 pointer approach where you use low -0 , high-2 and i scans thru
        // array
        int low = 0, high = nums.size() - 1, i = 0, temp = 0;
        while (i <= high) {
            if (nums[i] == 0) {
                swap(nums[i], nums[low]);
                low++;
                i++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[high]);
                high--;
            }
        }
    }
};