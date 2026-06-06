class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(int num:nums){
            if(++ump[num] > nums.size()/2){
                return num;
            }
        }
        
        // for(int num: nums){
        //     ump[num]++;
        // }
        // for(auto& it:ump){
        //     if (it.second > nums.size() / 2) {
        //         return it.first;
        //     }
        // }
        return -1;
    }
};