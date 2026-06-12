class Solution {
public:
    string reverseWords(string s) {
        //stringstream in cpp used to remove spcaes and make string as words
        stringstream ss(s);
        string word;
        vector<string> words;

        while(ss >> word){
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string res = "";
        for(int i = 0 ; i < words.size(); i++){
            res+=words[i];
            //if current word is not last word add space
            if(i != words.size()-1){
                res += " ";
            }
        }
        return res;
    }
};