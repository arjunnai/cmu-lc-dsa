class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes = 0, left = 0, count = 0;
        for(int right = 0 ; right < nums.size(); right++){
            if(nums[right] == 0){
                zeroes++;
            }
            if(zeroes > k){
                if(nums[left] == 0){
                    zeroes--;
                }
                left++;
            }else{
                count++;
            }
        }
        return count;
    }
};