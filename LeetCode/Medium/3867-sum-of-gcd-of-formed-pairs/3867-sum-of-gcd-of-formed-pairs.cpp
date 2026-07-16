class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefgcd(n);
        int mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            prefgcd[i] = gcd(nums[i], mx);
        }
        sort(prefgcd.begin(), prefgcd.end());
        long long ans = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            ans += gcd(prefgcd[l], prefgcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};