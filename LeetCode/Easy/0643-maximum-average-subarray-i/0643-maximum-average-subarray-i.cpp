class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0;
        double curr_sum = 0;
        for (int i = 0; i < k; i++) {
            curr_sum += nums[i];
        }
        double max_sum = curr_sum;

        for (int r = k; r < nums.size(); r++) {
            cout << "l: " << nums[l] << endl << "r: " << nums[r] << endl;
            curr_sum += nums[r] - nums[r - k];
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum / k;
    }
};