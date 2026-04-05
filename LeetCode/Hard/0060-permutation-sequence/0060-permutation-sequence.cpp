class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials(n, 1);
        vector<char> nums;

        // calc factorial (3! = 6)
        for (int i = 1; i < n; i++) {
            factorials[i] = factorials[i - 1] * i;
        }

        // shortcut for converting int to char, ascii for '0' is 48 so 1+48 = 49
        // which is '1'
        for (int i = 1; i <= n; i++) {
            nums.push_back(i + '0');
        }

        k = k - 1;
        string res = "";
        // for n = 4 We have 4 slots, so we look at the branch size of 3! (6).
        // 14 / 6 = 2. So we pick index 2 from our pool.
        for (int i = n; i > 0; i--) {
            int branchSize = factorials[i - 1];
            ////  "14 / 6 = 2"
            int idx = k / branchSize;
            // Pick index 2 from our pool and write it down
            res.push_back(nums[idx]);
            //"Remove it from the available pool"
            nums.erase(nums.begin() + idx);
            //"Update our target for the next branch down"
            k = k % branchSize;
        }
        return res;
    }
};