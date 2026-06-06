class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag;
        for (char c : magazine) {
            mag[c]++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            if (mag[ransomNote[i]] <= 0) {
                return false;
            }
            mag[ransomNote[i]]--;
        }
        return true;
    }
};