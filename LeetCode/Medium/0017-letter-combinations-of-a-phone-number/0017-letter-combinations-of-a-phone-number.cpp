class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mapping;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";
        if (digits.empty())
            return {};
        vector<string> res;
        string curr = "";
        dfs(res, curr, 0, mapping, digits);
        return res;
    }

    void dfs(vector<string>& res, string& curr, int idx,
             unordered_map<char, string>& mapping, const string& digits) {
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        //this is only trick here - 23 ; digits[0] = 2, mapping[2] = abc, then element will be a then do dfs on that so you get ad, ae, af...
        string letter = mapping[digits[idx]];
        for (const auto& element : letter) {
            curr.push_back(element);
            dfs(res, curr, idx + 1, mapping, digits);
            curr.pop_back();
        }
    }
};