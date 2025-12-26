auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<std::pair<int, int>> posSpeedPairs;
        for (int i = 0; i < position.size(); i++) {
            posSpeedPairs.push_back({position[i], speed[i]});
        }
        sort(posSpeedPairs.begin(), posSpeedPairs.end());
        int fleets = 0;
        double maxTime = 0.0;
        for (int i = posSpeedPairs.size() - 1; i >= 0; i--) {
            double time = (double)(target - posSpeedPairs[i].first) /
                          posSpeedPairs[i].second;
            if(time>maxTime){
                maxTime = time;
                fleets++;
            }
        }
        return fleets;
    }
};