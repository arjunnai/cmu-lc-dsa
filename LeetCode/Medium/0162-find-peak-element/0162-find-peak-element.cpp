class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] < nums[mid + 1]) {
                // peak is on right side
                l = mid + 1;
            } else
                r = mid;
        }
        return l;
    }
};