class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0, vowel = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                vowel++;
            }
        }
        int maxV = vowel;
        for (int r = k ; r < s.size(); r++) {
            if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' ||
                s[r] == 'u') {
                vowel = vowel + 1;
                l++;
            }
            if (s[r-k] == 'a' || s[r-k] == 'e' || s[r-k] == 'i' || s[r-k] == 'o' ||
                s[r-k] == 'u') {
                vowel--;
            }
            maxV = max(maxV, vowel);
        }
        return maxV;
    }
};