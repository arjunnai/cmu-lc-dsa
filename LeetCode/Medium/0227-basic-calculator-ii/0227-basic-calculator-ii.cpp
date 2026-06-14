class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char op = '+';
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                ans = ans * 10 + (c - '0');
            }
            //|| i == s.size() - 1 -> because last number is never followed by an op, so need to process it
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+')
                    st.push(ans);
                else if (op == '-')
                    st.push(-ans);
                else if (op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * ans);
                } else if (op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / ans);
                }
                op = c;
                ans = 0;
            }
        }

        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};