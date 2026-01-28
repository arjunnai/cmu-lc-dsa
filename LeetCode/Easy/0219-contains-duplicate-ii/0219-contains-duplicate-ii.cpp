class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> ust;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                ust.erase(nums[i - k - 1]);
            }
            if (ust.contains(nums[i])) {
                return true;
            }
            ust.insert(nums[i]);
        }
        return false;
    }
};