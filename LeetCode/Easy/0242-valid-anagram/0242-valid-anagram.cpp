class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        for(char c: s){
            smap[c]++;
        }

        for(char c: t){
            tmap[c]++;
        }
        if(smap != tmap){
            return false;
        }
        return true;
    }
};