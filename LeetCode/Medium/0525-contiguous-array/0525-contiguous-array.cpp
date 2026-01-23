class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> ump;
        int sum = 0, maxLen = 0;
        ump[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
            sum += nums[i];
            if (ump.contains(sum)) {
                maxLen = max(maxLen, i - ump[sum]);
            } else {
                ump[sum] = i;
            }
        }
        return maxLen;
    }
};

// 0,  1 , 1, 1, 1, 1,  0,  0,  0
//-1, 1 , 1, 1, 1, 1, -1, -1, -1
//-1, 0 , 1, 2, 3, 4, 3, 2, 1
