class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // brute force
        //     int newIdx = 0;
        //     vector<int> temp(nums.size());
        //     for(int i = 0 ; i < nums.size(); i++){
        //         newIdx = (i + k) % nums.size();
        //         temp[newIdx] = nums[i];
        //     }
        //     nums = temp;
        // }
        k = k % nums.size();
        // triple reversal
        reverse(nums.begin(), nums.end());
        // reverse first half
        reverse(nums.begin(), nums.begin() + k);
        // reverse second half
        reverse(nums.begin() + k, nums.end());
    }
};