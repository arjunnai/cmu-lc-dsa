class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        // create visited arrays
        vector<int> visited(isConnected.size(), 0);

        // helicopter kinda view to see which main province to visit first
        for (int i = 0; i < isConnected.size(); i++) {
            // check if city already visited, if not
            if (!visited[i]) {
                // land heli on city i, walk to all its friends that happens
                // inside dfs
                dfs(isConnected, visited, i);
                // count new province
                res++;
            }
        }
        return res;
    }
    // walk to all its friends
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int i) {
        // first mark the current city we landed on as visited so we dont
        // revisit again
        visited[i] = true;
        // check for friends
        for (int j = 0; j < isConnected.size(); j++) {
            // if direct road between 2 friends and if we haven't visited that
            // specific friend yet
            if (isConnected[i][j] == 1 && !visited[j]) {
                // visit them and mark as visited
                visited[j] = true;
                //travel to city j and repeat, keep going until dead end.
                dfs(isConnected, visited, j);
            }
        }
    }
};