class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,bool> visited;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int count = 1;
        while(!q.empty()) {
            int room = q.front();
            q.pop();
            
            for(int i=0;i<rooms[room].size();i++) {
                if(visited.find(rooms[room][i]) == visited.end()) {
                    count++;
                    visited[rooms[room][i]] = true;
                    q.push(rooms[room][i]);
                }
            }
        }
        return count == rooms.size();
    }
};