class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // discard any old value when new value coming in is bigger than rest of
        // older window data structure that allows adding and removing from both
        // the front and the back efficiently - deque
        deque<int> dq;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};