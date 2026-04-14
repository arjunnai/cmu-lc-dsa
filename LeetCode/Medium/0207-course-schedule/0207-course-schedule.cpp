class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // if i finish this course, which list of courses can i unlock
        unordered_map<int, vector<int>> graph;
        // how many more prereqs do I need to finish before being able to sit in
        // the class
        vector<int> inD(numCourses, 0);
        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            graph[prereq].push_back(course);
            inD[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inD[i] == 0) {
                // using i because 0 to numCourses  - 1;
                q.push(i);
            }
        }
        int taken = 0;
        while (!q.empty()) {
            int currCourse = q.front();
            q.pop();
            taken++;
            for (int neighbor : graph[currCourse]) {
                inD[neighbor]--;
                if (inD[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return taken == numCourses;
    }
};