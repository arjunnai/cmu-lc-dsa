class Solution {
public:
    int res = INT_MAX;
    int n;
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> children(k, 0);
        dfs(0, cookies, children, k);
        return res;
    }

    void dfs(int bagIndex, vector<int>& cookies, vector<int>& children, int k) {
        if (bagIndex >= n) {
            int unfair = *max_element(begin(children), end(children));
            res = min(res, unfair);
            return;
        }
        int currBag = cookies[bagIndex];
        for (int child = 0; child < k; child++) {
            children[child] += currBag;
            dfs(bagIndex + 1, cookies, children, k);
            children[child] -= currBag;
        }
    }
};