class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // int maxlen = 0, start = 0, zero = -1;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == 0) {
        //         start = zero + 1;
        //         zero = i;
        //     }
        //     maxlen = max(maxlen, i - start);
        // }
        // return maxlen;
        int l = 0 , zero = 0, len = 0, n = nums.size();
        for(int r = 0 ; r < n ; r++){
            if(nums[r] == 0)zero++;
            while(zero>1){
                if(nums[l] == 0)zero--;
                l++;
            }
            len = max(len, r - l);
        }
        return len;
    }
};