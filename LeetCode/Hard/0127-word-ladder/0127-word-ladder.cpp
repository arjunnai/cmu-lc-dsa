class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ust(wordList.begin(), wordList.end());
        if(ust.find(endWord) == ust.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            string temp = q.front().first;
            int val = q.front().second;
            q.pop();
            if(temp == endWord) return val;
            for(int i = 0 ; i < temp.size(); i++){
                char rep = temp[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    temp[i] = ch;
                    if(ust.find(temp) != ust.end()){
                        q.push({temp, val+1});
                        ust.erase(temp);
                    }
                }
                temp[i] = rep;
            }
        }
        return 0;
    }
};