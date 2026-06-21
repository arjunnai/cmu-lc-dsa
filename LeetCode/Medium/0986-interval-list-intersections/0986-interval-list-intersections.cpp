class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0, fsize = firstList.size(), ssize = secondList.size();
        while (i < fsize && j < ssize) {
            int fstart = firstList[i][0];
            int fend = firstList[i][1];
            int sstart = secondList[j][0];
            int send = secondList[j][1];
            int lo = max(fstart, sstart);
            int hi = min(fend, send);
            // this is to only add when overlaps eg [1,3][5,8] doesnt overlap without this it will just push it
            if (lo <= hi)
                res.push_back({lo, hi});
            //only advance smaller one forward
            if (fend < send)
                i++;
            else
                j++;
        }
        return res;
    }
};