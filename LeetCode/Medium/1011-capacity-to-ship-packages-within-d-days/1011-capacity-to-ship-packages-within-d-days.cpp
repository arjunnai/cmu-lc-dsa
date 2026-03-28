class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // highest would be sum of all numbers so we can fit all of it in 1 day
        // itself lowest would be the max number in the weights list (in eg 1 10
        // is max, it will take 7 days : 1: 1,2,3,4; 2: 5; 3:6; 4:7;  5:8;  6:9;
        // 7:10)
        int maxV = 0, sum = 0, ans = 0;
        for (int weight : weights) {
            if (weight > maxV)
                maxV = weight;
            sum += weight;
        }
        int low = maxV, high = sum;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int day = 1, currentWeight = 0;
            for (int weight : weights) {
                if (currentWeight + weight > mid) {
                    day++;
                    currentWeight = 0;
                }
                currentWeight = currentWeight + weight;
            }
            if (day > days) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};