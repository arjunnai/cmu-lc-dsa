class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s_nums;
        string ans = "";
        for (int num : nums) {
            s_nums.push_back(to_string(num));
        }

        sort(s_nums.begin(), s_nums.end(),
             [](string& a, string& b) { return a + b > b + a; });
            if(s_nums[0] == "0"){
               return "0"; 
            }
        for(int i = 0 ; i < s_nums.size(); i++){
            ans += s_nums[i];
        }
        return ans;
    }
};