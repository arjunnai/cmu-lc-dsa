class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> ump;
        string result = "";
        int n = s.size();
        int feasibility = (n + 1) / 2;
        for (int i = 0; i < n ; i++) {
            ump[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto iter : ump) {
            pq.push(make_pair(iter.second, iter.first));
        }
        if (!pq.empty()) {
            if (pq.top().first > feasibility) {
                return "";
            }
        }
        pair<int, char> previ;
        while (!pq.empty()) {
            pair<int, char> top = pq.top();
            top.first--;
            pq.pop();
            result += top.second;
            if (previ.first > 0) {
                pq.push(previ);
            }
            previ = top;

        }
        cout<<result;

        return result;
    }
};