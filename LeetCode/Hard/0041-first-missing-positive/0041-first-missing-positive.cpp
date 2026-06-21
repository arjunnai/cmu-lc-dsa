class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // unordered_map<int, int> ump;
        // for(int i = 0 ; i < nums.size(); i++){

        // }
        // sort(nums.begin(), nums.end());
        // int target = 1;
        // for (int n : nums) {
        //     if (n == target) {
        //         target++;
        //     } else if (n > target) {
        //         return target;
        //     }
        // }
        // return target;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            // place each value v at index v-1 eg: 1-> 0
            while (nums[i] >= 1 && nums[i] <= n &&
                   nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // find first index where value != index+1
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        // if everythig is present then we return n+1 
        return n + 1;
    }
};