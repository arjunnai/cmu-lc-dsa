class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, sum = 0;
        int l = 0, r = 1;
        while (r < prices.size()) {
            if (prices[r] - prices[l] < 0) {
                l = r;
            } else {
                profit = max(profit, prices[r] - prices[l]);
            }
            r++;
        }
        // profit = max(profit, sum);
        return profit;
    }
};