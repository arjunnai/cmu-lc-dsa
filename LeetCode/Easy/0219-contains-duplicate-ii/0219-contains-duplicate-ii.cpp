class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for (int r = 0; r < nums.size(); r++) {
            if (ump.contains(nums[r])) {
                if (abs(ump[nums[r]] - r) <= k) {
                    return true;
                }
            }
            ump[nums[r]] = r;
        }
        return false;
    }
};

// 0 1 2 3 4 5 6
// 1 0 1 1 k = 1
// l   r