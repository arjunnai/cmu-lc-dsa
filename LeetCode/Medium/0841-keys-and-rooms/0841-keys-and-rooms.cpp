class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(0, rooms, visited);
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
    void dfs(int currentRoom, vector<vector<int>>& rooms,
             vector<bool>& visited) {
        visited[currentRoom] = true;
        for (int i = 0; i < rooms[currentRoom].size(); i++) {
            if (!visited[rooms[currentRoom][i]]) {
                dfs(rooms[currentRoom][i], rooms, visited);
            }
        }
    }
};