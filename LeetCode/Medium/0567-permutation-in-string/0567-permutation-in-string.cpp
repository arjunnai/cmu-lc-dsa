class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int winLenght = s1.size();
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> s1Map(26, 0);
        vector<int> windowCount(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            s1Map[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++) {
            windowCount[s2[i]-'a']++;
            if (i - winLenght >= 0) {
                windowCount[s2[i - winLenght] - 'a']--;
            }
            if (s1Map == windowCount) {
                return true;
            }
        }
        return false;
    }
};