class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // need to find an earlier target towards left even if you found mid as
        // target
        int l = 0, r = nums.size() - 1, mid = 0, start = -1, end = -1;
        // find first occurence
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                start = mid;
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // find last occurence
        l = 0, r = nums.size()-1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                end = mid;
                l = mid + 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return {start, end};
    }
};