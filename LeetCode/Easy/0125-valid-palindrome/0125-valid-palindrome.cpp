class Solution {
public:
    bool isPalindrome(string s) {
        // string result = "";
        // for (char c : s) {
        //     if (isalnum(static_cast<unsigned char>(c))) {
        //         result += c;
        //     }
        // }
        // transform(result.begin(), result.end(), result.begin(),
        //           [](unsigned char c) { return tolower(c); });
        // int left = 0, right = result.size() - 1;
        // while (left <= right) {
        //     if (result[left] != result[right]) {
        //         return false;
        //     }
        //     left++;
        //     right--;
        // }
        // return true;
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            if (!isalnum(static_cast<unsigned char>(s[left])))  {
                left++;
                continue;
            }else if(!isalnum(static_cast<unsigned char>(s[right]))){
                right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};