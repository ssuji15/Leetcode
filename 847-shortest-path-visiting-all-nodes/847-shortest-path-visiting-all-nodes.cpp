class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        unordered_map<int,unordered_map<int,bool>> visited;
        queue<vector<int>> q;
        for(int i=0;i<graph.size();i++) {
            q.push({i,1<<i,0});
        }
        
        visited[0][1] = true;
        int endMask = (1 << graph.size()) - 1;
        while(!q.empty()) {
            int node = q.front()[0];
            int mask = q.front()[1];
            int cost = q.front()[2];
            q.pop();
            if(mask == endMask) return cost;
            for(int i=0;i<graph[node].size();i++) {
                int newNode = graph[node][i];
                int newMask = mask | (1 << newNode);
                if(visited.find(newNode) == visited.end()
                   || visited[newNode].find(newMask) == visited[newNode].end()) {
                    visited[newNode][newMask] = true;
                    q.push({newNode, newMask, cost+1});
                }
            }
        }
        return -1;
    }
};