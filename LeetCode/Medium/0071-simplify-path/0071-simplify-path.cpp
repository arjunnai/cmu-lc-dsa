class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token;
        // split on '/'
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!st.empty())
                    st.pop_back();
            } else {
                st.push_back(token);
            }
        }
        //  "/" + names joined by "/"
        string result = "";
        for (string& dir : st) {
            result += "/" + dir;
        }
        return result.empty() ? "/" : result;
    }
};