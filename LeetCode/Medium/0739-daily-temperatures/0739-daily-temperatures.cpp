class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;
        int maxT = 0;
        for (int i = 0; i < temperatures.size(); i++) {
            cout << temperatures[i] << "\n";
            while ( !st.empty() && temperatures[i] > temperatures[st.top()] ){
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);

            
        }
        return ans;
    }
};