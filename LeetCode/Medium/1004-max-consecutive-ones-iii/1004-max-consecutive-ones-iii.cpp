class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, zeros = 0, maxlen = 0;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0){
                zeros++;
                // cout << "Expanding: R=" << right << ", Zeros=" << zeros << endl;

                while(zeros>k){
                    if(nums[left] == 0){
                        zeros--;
                    }
                    left++;
                    // cout << "Shrinking: L=" << left << ", Zeros=" << zeros << endl;
                }
            }
            maxlen = max(maxlen, right - left + 1);
            // cout << "Window [" << left << "," << right << "] size: " << maxlen << endl;
        }
        return maxlen;
    }
};