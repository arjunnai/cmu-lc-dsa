class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> ump;
        
        // Pass 1: Find Potential Candidates
        for (int x : nums) {
            ump[x]++;
            
            // If we have too many candidates (more than 2), let them fight
            if (ump.size() > 2) {
                // We need an iterator to safely delete while looping
                auto it = ump.begin();
                while (it != ump.end()) {
                    it->second--; // Decrement count (battle damage)
                    
                    if (it->second == 0) {
                        // erase() returns the iterator to the next element
                        it = ump.erase(it); 
                    } else {
                        ++it;
                    }
                }
            }
        }
        
        // Pass 2: Verify the Survivors
        // (Just because they survived doesn't mean they actually have > n/3 votes)
        vector<int> result;
        for (auto& pair : ump) {
            int candidate = pair.first;
            int actualCount = 0;
            
            // Manual count check
            for (int n : nums) {
                if (n == candidate) actualCount++;
            }
            
            if (actualCount > nums.size() / 3) {
                result.push_back(candidate);
            }
        }
        
        return result;
    }
};