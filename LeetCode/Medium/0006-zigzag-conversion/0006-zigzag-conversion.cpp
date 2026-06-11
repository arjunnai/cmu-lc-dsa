class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows)
            return s;
        int n = s.size();
        vector<string> rows(numRows);

        int currRow = 0;
        bool goingDown = false;
        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            // move to next row based on true or false of going down
            currRow += goingDown ? 1 : -1;
        }
        string res = "";
        for (string row : rows) {
            res += row;
        }
        return res;
    }
};