class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        vector<int> psum(nums.size() + 1);
        psum[0] = 0;
        seen[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            psum[i] = psum[i - 1] + nums[i - 1];
            int rem = psum[i] % k;
            if (seen.count(rem)) {
                if (i - seen[rem] >= 2)
                    return true;
            } else {
                seen[rem] = i;
            }
        }

        // tle exceeded
        //  for (int l = 0; l < psum.size(); l++) {
        //      for (int r = l + 1; r < psum.size(); r++) {
        //          if ((psum[r] - psum[l]) % k == 0 && r - l >= 2) {
        //              return true;
        //          }
        //      }
        //  }

        return false;
    }
};