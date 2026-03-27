class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_value = 0;
        for (int element : piles) {
            if (element > max_value) {
                max_value = element;
            }
        }

        cout << max_value << endl;
        int low = 1, high = max_value;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours += piles[i] / mid;
                if (piles[i] % mid != 0) {
                    hours += 1;
                }
            }
            if (hours <= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

// 30 11 23 4 20
//max = 30
// 1 < 30
// mid = 15
//hours = 0
// 0 -> 4 i
// 2 1 2 1 2
// low = 16 
//mid = 23
//2 1 1 1 1

