class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, currlen = 0, minlen = INT_MAX;
        int curr_sum = 0;
        for (int r = 0; r < nums.size(); r++) {
            curr_sum += nums[r];
            while (curr_sum >= target) {
                currlen = r - l + 1;
                // cout << "currlen: " << currlen << endl;
                // find min len first
                minlen = min(currlen, minlen);
                // since we need to remove l from the sum, we subtract nums[l],
                // then do l++
                curr_sum -= nums[l];
                l++;
            }
        }
        //if minlen is still intmax, means no update, no valid subarray, so return 0
        return (minlen == INT_MAX) ? 0 : minlen;
    }
};

// 2 3 1 2 4 3
