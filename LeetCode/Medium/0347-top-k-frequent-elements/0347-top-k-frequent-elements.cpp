class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurence;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            occurence[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto entry : occurence) {
            pq.push({entry.second, entry.first});
        }
        for (int i = 0; i < k ; i++){
            // pair<int, int> topElt = pq.top();
            auto topElt = pq.top();
            res.push_back(topElt.second);
            pq.pop();
        }
        return res;
    }
};