class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        for (int x : a) {
            while (x < 0 && !st.empty() && st.top() > 0) {
                if (st.top() < abs(x)) {
                    st.pop();
                    continue;
                }
                if (st.top() == abs(x)) {
                    st.pop();
                }
                x = 0;
                break;
            }
            if (x != 0)
                st.push(x);
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};