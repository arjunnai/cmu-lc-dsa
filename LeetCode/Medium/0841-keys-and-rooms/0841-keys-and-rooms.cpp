class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // bfs
        int n = rooms.size();
        vector<bool> visited(n, false);
        // queue<int> q;

        // // visit 0th room
        // visited[0] = true;
        // q.push(0);

        // int count = 1;
        // while (!q.empty()) {
        //     int curr = q.front();
        //     q.pop();
        //     for (int key : rooms[curr]) {
        //         if (!visited[key]) {
        //             visited[key] = true;
        //             q.push(key);
        //             count++;
        //         }
        //     }
        // }
        // return count == n;

        // dfs
        dfs(0, rooms, visited);
        for (bool v : visited) {
            if (!v)
                return false;
        }
        return true;
    }
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
        if (visited[room] == true)
            return;
        visited[room] = true;

        for (int key : rooms[room]) {
            dfs(key, rooms, visited);
        }
    }
};