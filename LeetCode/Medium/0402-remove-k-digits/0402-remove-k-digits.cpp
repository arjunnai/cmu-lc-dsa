class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        int start = 0;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        while (k > 0) {
            st.pop_back();
            k--;
        }

        while (start < st.size() && st[start] == '0')
            start++;
        st = st.substr(start);

        return st.empty() ? "0" : st;
    }
};