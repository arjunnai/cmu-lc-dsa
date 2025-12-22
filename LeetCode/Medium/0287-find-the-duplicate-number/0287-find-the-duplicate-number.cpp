class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        //proves we have a cycle
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
            slow = 0;
        // find where cycle is
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

//      1 3 4 2 2 
// slow 1 3 2 4
// fast 3 4 4 4
//s2.0  1 3 2 
//f2 4. 2 4 2