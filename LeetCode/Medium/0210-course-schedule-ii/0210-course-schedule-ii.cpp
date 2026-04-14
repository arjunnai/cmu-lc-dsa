class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        vector<int> inD(numCourses, 0);
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            graph[prereq].push_back(course);
            inD[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inD[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;
        while (!q.empty()) {
            int currCourse = q.front();
            q.pop();
            res.push_back(currCourse);
            for (int neighbor : graph[currCourse]) {
                inD[neighbor]--;
                if (inD[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};