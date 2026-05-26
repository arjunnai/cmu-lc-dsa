class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string w = q.front(); q.pop();
                if (w == endWord) return steps;
                for (int j = 0; j < (int)w.size(); j++) {
                    char orig = w[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orig) continue;
                        w[j] = c;
                        if (dict.count(w)) { dict.erase(w); q.push(w); }
                    }
                    w[j] = orig;
                }
            }
            steps++;
        }
        return 0;
    }
};