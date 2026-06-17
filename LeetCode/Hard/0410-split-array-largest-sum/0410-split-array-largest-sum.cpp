class Solution {
public:
    bool cansplit(int sum, vector<int>& nums, int k) {
        int count = 1, total = 0;
        for (int num : nums) {
            total += num;
            if (total > sum) {
                total = num;
                count++;
            }
            if (count > k)
                return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxn = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxn = max(maxn, nums[i]);
            sum += nums[i];
        }
        int l = maxn, r = sum;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (cansplit(mid, nums, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};