class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> ust(wordList.begin(), wordList.end());
        if (ust.find(endWord) == ust.end())
            return 0;
            
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            string tempstr = q.front().first;
            int tempval = q.front().second;
            q.pop();
            if (tempstr == endWord) {
                return tempval;
            }
            for (int i = 0; i < tempstr.size(); i++) {
                char charReplace = tempstr[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    tempstr[i] = ch;
                    if (ust.find(tempstr) != ust.end()) {
                        q.push({tempstr, tempval + 1});
                        ust.erase(tempstr);
                    }
                }
                tempstr[i] = charReplace;
            }
        }
        return 0;
    }
};