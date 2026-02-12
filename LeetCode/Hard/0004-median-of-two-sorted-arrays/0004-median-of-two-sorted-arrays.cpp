class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const vector<int>& A = (nums1.size() < nums2.size()) ? nums1 : nums2;
        const vector<int>& B = (nums1.size() < nums2.size()) ? nums2 : nums1;
        int m = A.size(), n = B.size();
        int totalSize = m + n;
        int half = totalSize / 2;
        int l = -1, r = m - 1;
        while (true) {
            int midA = l + (r - l) / 2;
            int midB = half - midA - 2;
            int Aleft = (midA >= 0) ? A[midA] : INT_MIN;
            int Bleft = (midB >= 0) ? B[midB] : INT_MIN;
            int Aright = ((midA + 1) < m) ? A[midA + 1] : INT_MAX;
            int Bright = ((midB + 1) < n) ? B[midB + 1] : INT_MAX;
            if (Aleft <= Bright && Bleft <= Aright) {
                if (totalSize % 2 == 1) {
                    return min(Aright, Bright);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                r = midA - 1;
            } else {
                l = midA + 1;
            }
        }
    }
};