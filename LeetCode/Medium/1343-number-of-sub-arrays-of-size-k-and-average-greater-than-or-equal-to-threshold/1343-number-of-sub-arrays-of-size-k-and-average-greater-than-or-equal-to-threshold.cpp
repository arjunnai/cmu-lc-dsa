class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int count = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if (sum >= threshold * k) {
            count++;
        }
        for (int l = 0, r = k; r < arr.size(); r++) {
            sum = sum + arr[r] - arr[l];

            if (sum >= threshold * k) {
                count++;
            }
            l++;
        }
        return count;
    }
};
