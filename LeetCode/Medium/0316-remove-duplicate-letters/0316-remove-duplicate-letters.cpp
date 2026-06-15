class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastidx(26, 0);
        for (int i = 0; i < s.size(); i++) {
            lastidx[s[i] - 'a'] = i;
        }
        vector<bool> seen(26, false);
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (seen[curr])
                continue;
            while (!st.empty() && s[i] < st.top() &&
                   lastidx[st.top() - 'a'] > i) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i] - 'a'] = true;
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};