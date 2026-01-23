class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // find peak, check mid and mid+1 (compare low and high and move left or
        // right ), at one poitn l == r, return that.
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else if (nums[mid] > nums[mid + 1]) {
                r = mid;
            }
        }
        return l;
    }
};