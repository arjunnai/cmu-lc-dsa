class Solution {
public:
    int maxScore;
    int n;

    void dfs(int idx, vector<string>& words, vector<int>& score, int currScore,
             vector<int>& freq) {
        maxScore = max(maxScore, currScore);
        // oob condition
        if (idx >= n)
            return;
        // we need to check if we can even pick the word.
        int tempScore = 0;
        int i = 0;
        vector<int> tempFreq = freq;

        for (i = 0; i < words[idx].size(); i++) {
            char ch = words[idx][i];
            // we took one letter
            tempFreq[ch - 'a']--;
            tempScore += score[ch - 'a'];
            // if tempFreq goes below 0, it means that letter does not exist
            if (tempFreq[ch - 'a'] < 0)
                break;
        }
        // take
        if (i == words[idx].size()) { // we were able to form the word with the
                                      // letters explore
            dfs(idx + 1, words, score, currScore + tempScore, tempFreq);
        }
        // not take it sitll has original freq
        dfs(idx + 1, words, score, currScore, freq);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        maxScore = INT_MIN, n = words.size();
        vector<int> freq(26, 0);

        // store character - frequencei n a map
        for (char& ch : letters) {
            freq[ch - 'a']++;
        }

        dfs(0, words, score, 0, freq);

        return maxScore;
    }
};