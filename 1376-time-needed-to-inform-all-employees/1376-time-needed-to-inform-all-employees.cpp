class Solution {
public:
    
    int totalTime = INT_MIN;
    void dfs(int node, unordered_map<int,vector<int>> &adjacentNodes, int time,
             vector<int>& informTime) {

        time += informTime[node];
        if(adjacentNodes[node].size() == 0) {
            totalTime = max(totalTime, time);
            return;
        }
        
        for(int i=0;i<adjacentNodes[node].size();i++) {
            dfs(adjacentNodes[node][i], adjacentNodes, time, informTime);
        }
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> adjacentNodes;
        
        for(int i=0;i<n;i++) {
            adjacentNodes[i] = {};
        }
        
        for(int i=0;i<manager.size();i++) {
            if(manager[i] != -1) {
                adjacentNodes[manager[i]].push_back(i);
            }
        }
        
        dfs(headID, adjacentNodes, 0, informTime);
        return totalTime;
    }
};