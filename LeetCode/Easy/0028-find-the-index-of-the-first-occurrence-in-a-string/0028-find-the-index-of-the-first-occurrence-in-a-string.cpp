class Solution {
public:
    int strStr(string haystack, string needle) {
        // int start = -1;
        // int needleidx = 0;
        // for(int i = 0 ; i < haystack.size(); i++){
        //     if(haystack[i] == needle[i]){
        //         needleidx++;
        //     }else{
        //         needleidx = 0;
        //     }

        //     if(needleidx == needle.size()){
        //         return i - needle.size() + 1;
        //     }
        // }
        int i = 0, j = 0, start = 0;
        while (i < haystack.size() && j < needle.size()) {
            start = i;
            while (i < haystack.size() && j < needle.size() &&
                   haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == needle.size()) {
                return start;
            }
            i = start + 1;
            // i++;
            j = 0;
        }
        return -1;
    }
};

// i
// sadbutsad
// j
// sad