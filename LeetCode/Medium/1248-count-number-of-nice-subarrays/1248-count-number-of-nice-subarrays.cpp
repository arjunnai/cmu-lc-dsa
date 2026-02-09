class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, odd = 0, left = 0, mid = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (isOdd(nums[right])) {
                odd += 1;
            }
            while (odd > k) {
                if (isOdd(nums[left])) {
                    odd -= 1;
                }
                left += 1;
                mid = left;
            }
            if(odd == k){
                while(!isOdd(nums[mid])){
                    mid += 1;
                }
                res += (mid - left) + 1;
            }
        }
        return res;
    }
    bool isOdd(int n) {
        return n % 2 != 0;
    }
};
