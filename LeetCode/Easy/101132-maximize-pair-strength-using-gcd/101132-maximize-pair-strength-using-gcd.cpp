class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int size = nums.size();
        long long best = 0;
        for (int first = 0; first < size; ++first) {
            for (int second = first + 1; second < size; ++second) {
                long long divisor = gcd(nums[first], nums[second]);
                long long strength =
                    (nums[first] / divisor) * (nums[second] / divisor);
                best = max(best, strength);
            }
        }
        return best;
    }
};