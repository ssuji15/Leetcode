class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int count = 0;
        unordered_map<int, vector<int>> adjacentNodes;
        unordered_map<int, vector<int>> incomingNodes;
        vector<bool> canReach(n, false);
        canReach[0] = true;
        queue<int> q;
        q.push(0);
        
        for(int i=0;i<connections.size();i++) {
            adjacentNodes[connections[i][0]].push_back(connections[i][1]);
            incomingNodes[connections[i][1]].push_back(connections[i][0]);
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int i=0;i<incomingNodes[node].size();i++) {
                canReach[incomingNodes[node][i]] = true;
                q.push(incomingNodes[node][i]);
            }
            
            for(int i=0;i<adjacentNodes[node].size();i++) {
                if(!canReach[adjacentNodes[node][i]]) {
                    count++;
                    canReach[adjacentNodes[node][i]] = true;
                    q.push(adjacentNodes[node][i]);
                }
            }
        }
        return count;
    }
};