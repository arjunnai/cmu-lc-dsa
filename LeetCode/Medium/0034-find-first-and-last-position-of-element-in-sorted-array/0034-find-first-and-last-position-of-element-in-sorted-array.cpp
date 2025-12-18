class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool isFirst = true;
        int fbs = binSearch(nums, target, isFirst);
        int sbs = binSearch(nums, target, !isFirst);
        return {fbs, sbs};
    }

    int binSearch(vector<int>& nums, int target, bool isFirst) {
        int left = 0, right = nums.size() - 1;
        int idx = -1;
        while (left <= right) {
            int mid = (left + (right - left)/2) ;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                idx = mid;
                if (isFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return idx;
    }
};