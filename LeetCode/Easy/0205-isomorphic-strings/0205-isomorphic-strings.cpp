class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> stot;
        unordered_map<char, char> ttos;
        for (int i = 0; i < s.size(); i++) {
            char sc = s[i];
            char tc = t[i];
            if (stot.contains(sc)) {
                if (stot[sc] != tc) {
                    return false;
                }
            } else {
                if (ttos.contains(tc)) {
                    return false;
                }
                stot[sc] = tc;
                ttos[tc] = sc;
            }
        }
        return true;
    }
};