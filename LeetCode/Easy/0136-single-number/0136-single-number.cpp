class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 1 xor 1 = 0 2 ^ 0 = 2 
        int ans = 0;
        for (int i = 0 ; i < nums.size(); i++){
            ans  = ans ^ nums[i];
        }
        return ans;
    }
};