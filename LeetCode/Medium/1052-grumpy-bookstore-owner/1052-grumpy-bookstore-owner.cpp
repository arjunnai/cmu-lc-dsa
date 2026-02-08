class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int cust = 0, totalSatisfied = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                cust += customers[i];
            }
        }

        int maxCust = cust, left = 0;
        for (int right = minutes; right < customers.size(); right++) {
            if (grumpy[right] == 1) {
                cust += customers[right];
            }
            if (grumpy[left] == 1) {
                cust -= customers[left];
            }
            left++;
            maxCust = max(maxCust, cust);
        }
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                totalSatisfied += customers[i];
            }
        }
        return totalSatisfied + maxCust;
    }
};