class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0)
            return 0;
        int cnt = 1, prevVar = nums[0], longest = 1;

        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - 1) == prevVar) {
                cnt++;
                longest = max(longest, cnt);
            } else if (nums[i] == nums[i - 1]) {
                continue;
            } else {
                cnt = 1;
            }
            prevVar = nums[i];
        }
        return longest;
    }
};