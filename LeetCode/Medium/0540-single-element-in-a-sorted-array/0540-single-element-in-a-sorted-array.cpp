class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l<r) {
            int mid = (l + r) / 2;
            if (mid % 2 != 0) {
                mid--;
            }
            if (nums[mid] == nums[mid + 1]) {
                // since we checked mid and mid+1, so we know the break can't be
                // at mid or mid + 1, so we check next
                l = mid + 2;
            } else if (nums[mid] != nums[mid + 1]) {
                r = mid;
            }
        }
        // after loop runs through and l==r, we land on last number which we return
        return nums[l];
    }
};

// 1,1,2,3,3,4,4,8,8
// 0,1,2,3,4,5,6,7,8
// all 2 pairs start at even indexes, from the point where there is an odd
// index, thats where we know its broken