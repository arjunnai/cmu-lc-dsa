class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, profit = 0, maxPro = 0;
        for (int r = 1; r < prices.size(); r++) {
            profit = prices[r] - prices[l];
            if (profit > 0) {
                maxPro = max(profit, maxPro);
            } else {
                l = r;
            }
        }
        return maxPro;
    }
};