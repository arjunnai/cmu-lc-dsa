class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int rank[26];
        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string& a = words[i];
            string& b = words[i + 1];
            int j = 0;
            while (j < a.size() && j < b.size()) {
                if (a[j] != b[j]) {
                    if (rank[a[j] - 'a'] > rank[b[j] - 'a'])
                        return false;
                    break;
                }
                j++;
            }
            // b ended a longer
            /// longer word before prefix false
            if (j == b.size() && a.size() > b.size())
                return false;
        }
        return true;
    }
};