class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - k;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // Check if starting at mid is valid (arr[mid] is closer or equal to
            // arr[mid+k])
            if (x - arr[mid] > arr[mid + k] - x) {
                // arr[mid + k] is closer, should start after mid (moving window right)
                l = mid + 1;
            } else {
                // arr[mid] is closer or equal, this is a valid start
                r = mid;
            }
        }
        // l and r at best starting index
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};