class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, n = nums.size(), res = INT_MAX;
        for (int r = 0; r < n; r++) {
            // if (nums[r] <= nums[l] * k) {
            //     res = nums.size() - r + l - 1;
            // }else{
            //     l++;
            // }
            while (nums[r] > (long long)nums[l] * k){
                l++;
            }
            int removals = nums.size() - (r-l) - 1;
            res = min(res, removals);

        }
        return res;
    }
};