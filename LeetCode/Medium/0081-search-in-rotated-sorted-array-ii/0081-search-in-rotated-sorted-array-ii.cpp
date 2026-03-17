class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            // only check to see if elements are same, if they are move pointers
            // inwards cuz we know target aren't going to be present in the left
            // right or mid one
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid - 1;
                } else
                    left = mid + 1;
            } else {
                if (nums[right] >= target && target >= nums[mid]) {
                    left = mid + 1;
                } else
                    right = mid - 1;
            }
        }
        return false;
    }
};