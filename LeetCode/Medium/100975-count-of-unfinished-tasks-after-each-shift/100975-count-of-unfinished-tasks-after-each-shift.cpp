class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int taskcount = tasks.size();
        vector<long long> prefix(taskcount + 1, 0);
        for (int i = 0; i < taskcount; i++) {
            prefix[i + 1] = prefix[i] + tasks[i];
        }
        long long totalWork = prefix[taskcount];
        long long workDone = 0;
        vector<int> answer;
        answer.reserve(shifts.size());
        for (int shiftTime : shifts) {
            workDone += shiftTime;
            if (workDone >= totalWork) {
                workDone = 0;
                answer.push_back(0);
            } else {
                int finished =
                    int(upper_bound(prefix.begin(), prefix.end(), workDone) -
                        prefix.begin()) -
                    1;
                answer.push_back(taskcount - finished);
            }
        }
        return answer;
    }
};