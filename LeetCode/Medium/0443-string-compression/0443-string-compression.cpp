class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int i = 0;
        while (i < chars.size()) {
            char c = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == c) {
                count++;
                i++;
            }
            chars[write++] = c;
            if (count > 1) {
                for (char d : to_string(count)) {
                    chars[write++] = d;
                }
            }
        }
        return write;
    }
};