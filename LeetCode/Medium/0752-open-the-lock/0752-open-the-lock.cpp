class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // putting deadends in visited set too so we dont have to initialise
        // another set for it
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000"))
            return -1;

        // intiialise q to hold both the currnet lock state and the moves
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visited.insert("0000");

        while (!q.empty()) {
            pair<string, int> curr = q.front();
            q.pop();
            if (curr.first == target)
                return curr.second;

            // generate 8 neighbours = each wheel can have 2 up or down and
            // there are 4 wheels so 8 neighbours
            for (int i = 0; i < 4; i++) {
                char og = curr.first[i];
                // og - '0' converts the char '0' (ASCII 48) into the actual
                // integer 0.
                //  + '0' converts integer 9 back into the character '9' (ASCII
                //  57) so it can be stored as string
                curr.first[i] = ((og - '0') + 1) % 10 + '0';
                if (!visited.count(curr.first)) {
                    visited.insert(curr.first);
                    q.push({curr.first, curr.second + 1});
                }
                curr.first[i] = ((og - '0') - 1 + 10) % 10 + '0';
                if (!visited.count(curr.first)) {
                    visited.insert(curr.first);
                    q.push({curr.first, curr.second + 1});
                }

                curr.first[i] = og;
            }
        }
        return -1;
    }
};