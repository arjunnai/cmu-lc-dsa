class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool flag = true; // true >> false <<
        int count = 0;
        if (nums.size() < 4)
            return false;
        if (nums[0] < nums[1])
            count++;
        else
            return false;

        for (int i = 1; i < nums.size()-1; i++) {
            if (nums[i] == nums[i + 1] || count > 3)
                return false;
            if (flag && nums[i] > nums[i + 1]) {
                count++;
                flag = false;
            } else if (!flag && nums[i] < nums[i + 1]) {
                count++;
                flag = true;
            }
        }
        return count == 3;
    }
};