class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i = 0 ; i < nums.size(); i++){
            // 1 0 0 4
            if (i > maxReach){
                return false;
            }
            // if ((i+nums[i])>maxReach){

            // }
            maxReach = max(maxReach, (i+nums[i]));
        }

        return true;
    }
};