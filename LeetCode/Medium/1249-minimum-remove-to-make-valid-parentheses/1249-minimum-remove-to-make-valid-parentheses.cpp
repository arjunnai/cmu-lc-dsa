auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {

                    st.pop();

                } else {
                    s[i] = '*';
                }
            }
        }
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        string result = "";
        for (char c : s) {
            if (c != '*') {
                result += c;
            }
        }
        return result;
    }
};
