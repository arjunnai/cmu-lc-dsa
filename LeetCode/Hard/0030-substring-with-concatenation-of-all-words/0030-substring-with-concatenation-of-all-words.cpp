// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         vector<int> res;
//         int numwords = words.size();
//         int wordlen = words[0].size();
//         int windowlen = numwords * wordlen;
//         unordered_map<string, int> need;
//         for (string& w : words) {
//             need[w]++;
//         }

//         for (int i = 0; i + windowlen <= s.size(); i++) {
//             unordered_map<string, int> have;
//             int j = 0;
//             //chopping window into numwords
//             while (j < numwords) {
//                 // substr (start, len) 0,3 then 3, 3
//                 string chunk = s.substr(i + j * wordlen, wordlen);
//                 if (!need.contains(chunk))
//                     break;
//                 have[chunk]++;
//                 // if count greater then break
//                 if (have[chunk] > need[chunk])
//                     break;
//                 j++;
//             }
//             if (j == numwords)
//                 res.push_back(i);
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int numwords = words.size();
        int wordlen = words[0].size();
        int windowlen = numwords * wordlen;
        int n = s.size();
        if (windowlen > n) return res;

        unordered_map<string, int> need;
        for (string& w : words) need[w]++;

        for (int offset = 0; offset < wordlen; offset++) {
            unordered_map<string, int> have;
            int left = offset;  
            int count = 0; 

            for (int right = offset; right + wordlen <= n; right += wordlen) {
                string word = s.substr(right, wordlen);   
                if (need.contains(word)) {
                    have[word]++;
                    count++;
                    while (have[word] > need[word]) {
                        string leftWord = s.substr(left, wordlen);
                        have[leftWord]--;
                        count--;
                        left += wordlen;
                    }
                    if (count == numwords) {
                        res.push_back(left);
                        string leftWord = s.substr(left, wordlen);
                        have[leftWord]--;
                        count--;
                        left += wordlen;
                    }
                } else {
                    have.clear();
                    count = 0;
                    left = right + wordlen;
                }
            }
        }
        return res;
    }
};