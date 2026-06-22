class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string words;
        vector<string> ans;
        while (ss >> words) {
            ans.push_back(words);
        }
        reverse(ans.begin(), ans.end());
        string result = "";
        for (int i = 0; i < ans.size(); i++) {
            if (i > 0)
                result += " ";
            result += ans[i];
        }
        return result;
    }
};