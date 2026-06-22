class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        string t1, t2;
        while (ss1.good() || ss2.good()) {
            int n1 = 0, n2 = 0;
            if (getline(ss1, t1, '.'))
                n1 = stoi(t1);
            if (getline(ss2, t2, '.'))
                n2 = stoi(t2);
            if (n1 < n2) {
                return -1;
            } else if (n1 > n2) {
                return 1;
            }
        }
        return 0;
    }
};