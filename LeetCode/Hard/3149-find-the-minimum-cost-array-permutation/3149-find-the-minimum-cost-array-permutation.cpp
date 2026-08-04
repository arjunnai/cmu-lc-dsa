class Solution {
public:
    int n;
    int minScore = INT_MAX;
    vector<int> resPerm;
    vector<int> findPermutation(vector<int>& nums) {
        n = nums.size();
        vector<bool> visited(n, false);

        vector<int> perm = {0};
        visited[0] = true;

        dfs(nums, visited, perm, 0);
        return resPerm;
    }

    void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& perm,
             int score) {
        if (score > minScore)
            return;
        if (perm.size() == n) {
            score += abs(perm.back() - nums[perm[0]]);
            if (minScore > score) {
                minScore = score;
                resPerm = perm;
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                perm.push_back(i);
                int s = perm.size();
                dfs(nums, visited, perm,
                    score + abs(perm[s - 2] - nums[perm[s - 1]]));
                visited[i] = false;
                perm.pop_back();
            }
        }
    }
};