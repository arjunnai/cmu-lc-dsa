class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> st;
        unordered_map<int, int> nge;
        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                nge[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        for (int num : nums1) {
            if (nge.contains(num)) {
                res.push_back(nge[num]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};