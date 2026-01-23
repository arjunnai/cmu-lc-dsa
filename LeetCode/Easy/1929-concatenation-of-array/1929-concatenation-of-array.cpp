class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(2*nums.size(), 0);
        for(int i = 0 ; i < nums.size(); i++){
            res[i]=nums[i];
        }
        for(int i = nums.size() ; i < 2*nums.size(); i++){
            res[i] = nums[i-nums.size()];
        }
        return res;
    }
};