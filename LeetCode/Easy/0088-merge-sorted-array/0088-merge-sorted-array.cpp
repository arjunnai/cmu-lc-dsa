class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int m1 = m - 1, n1 = n - 1, widx = nums1.size() - 1;
        while (m1 >= 0 && n1 >= 0) {
            if (nums1[m1] >= nums2[n1]) {
                nums1[widx] = nums1[m1];
                m1--;
                widx--;
            } else {
                nums1[widx] = nums2[n1];
                n1--;
                widx--;
            }
        }
        while (n1 >= 0) {
            nums1[widx] = nums2[n1];
            n1--;
            widx--;
        }
    }
};