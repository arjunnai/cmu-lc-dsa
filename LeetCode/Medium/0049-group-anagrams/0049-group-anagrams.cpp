class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> ump;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            ump[key].push_back(s);
        }
        for (auto& iter : ump) {
            ans.push_back(iter.second);
        }
        return ans;
    }
};