auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //this is so that in case there's nothing smaller, there will be 0 at the very end so the stack will do the while loop logic
        heights.push_back(0);
        stack<int> st;
        int area = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int idx = st.top();
                st.pop();
                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                area = max(area, (heights[idx] * width));
            }
            st.push(i);
        }
        return area;
    }
};