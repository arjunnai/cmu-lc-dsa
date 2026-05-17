class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target)
            return 0;
        unordered_map<int, vector<int>> stopToBuses;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }
        queue<pair<int, int>> q; // currstop and bus taken
        unordered_set<int> visitedStop;
        vector<bool> visitedBus(routes.size(), false);
        q.push({source, 0});
        visitedStop.insert(source);

        while (!q.empty()) {
            auto [currStop, busesTaken] = q.front();
            q.pop();
            for (int bus : stopToBuses[currStop]) {
                if (visitedBus[bus])
                    continue;
                visitedBus[bus] = true;
                int newBus = busesTaken + 1;
                for (int nextStop : routes[bus]) {
                    if (nextStop == target) {
                        return newBus;
                    }

                    if (!visitedStop.count(nextStop)) {
                        visitedStop.insert(nextStop);
                        q.push({nextStop, newBus});
                    }
                }
            }
        }
        return -1;
    }
};