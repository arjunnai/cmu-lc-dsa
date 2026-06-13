class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int i = 0;
        int n = asteroids.size();
        while (i < n) {
            if (st.empty() || asteroids[i] > 0 || st.top() < 0)
                st.push(asteroids[i++]);
            else if (st.top() > abs(asteroids[i]))
                i++;
            else if (st.top() == abs(asteroids[i]))
                st.pop(), i++;
            else
                st.pop();
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};