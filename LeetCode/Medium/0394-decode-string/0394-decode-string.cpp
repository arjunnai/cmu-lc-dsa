class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> nums;

        string ans = "";
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                nums.push(num);
                st.push(ans);
                ans = "";
                num = 0;
            } else if (s[i] == ']') {
                int count = nums.top();
                nums.pop();

                string prev = st.top();
                st.pop();

                string temp = "";
                while (count--) {
                    temp += ans;
                }
                ans = prev + temp;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};