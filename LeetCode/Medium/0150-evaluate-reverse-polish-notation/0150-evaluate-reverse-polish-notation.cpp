class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" &&
                tokens[i] != "/") {
                s.push(stoi(tokens[i]));
            } else {
                int l1 = s.top();
                s.pop();
                int l2 = s.top();
                s.pop();
                if (tokens[i] == "+") {
                    s.push(l1 + l2);
                } else if (tokens[i] == "-") {
                    s.push(l2 - l1);
                } else if (tokens[i] == "*") {
                    s.push(l1 * l2);
                } else if (tokens[i] == "/") {
                    s.push(l2 / l1);
                }
            }
        }
        return s.top();
    }
};