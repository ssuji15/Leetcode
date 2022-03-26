class Solution {
public:

    void dfs(int node, unordered_map<int,vector<int>> &redAdjacent,
            unordered_map<int,vector<int>> &blueAdjacent, vector<int> &blueDistance,
            vector<int> &redDistance) {
        if(blueDistance[node] != INT_MAX) {
            for(int i=0;i<redAdjacent[node].size();i++) {
                int newNode = redAdjacent[node][i];
                int newDistance = blueDistance[node] + 1;
                if(newDistance < redDistance[newNode]) {
                    redDistance[newNode] = newDistance;
                    dfs(newNode, redAdjacent, blueAdjacent, blueDistance, redDistance);
                }
            }
        }
        
        if(redDistance[node] != INT_MAX) {
            for(int i=0;i<blueAdjacent[node].size();i++) {
                int newNode = blueAdjacent[node][i];
                int newDistance = redDistance[node] + 1;
                if(newDistance < blueDistance[newNode]) {
                    blueDistance[newNode] = newDistance;
                    dfs(newNode, redAdjacent, blueAdjacent, blueDistance, redDistance);
                }
            }
        }
        
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int,vector<int>> redAdjacent;
        unordered_map<int,vector<int>> blueAdjacent;
        
        for(int i=0;i<redEdges.size();i++) {
            redAdjacent[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        
        for(int i=0;i<blueEdges.size();i++) {
            blueAdjacent[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        
        vector<int> blueDistance(n,INT_MAX);
        vector<int> redDistance(n,INT_MAX);
        blueDistance[0] = 0;
        redDistance[0] = 0;
        dfs(0,redAdjacent,blueAdjacent, blueDistance, redDistance);
        
        for(int i=0;i<n;i++) {
            blueDistance[i] = min(blueDistance[i], redDistance[i]);
            if(blueDistance[i] == INT_MAX) blueDistance[i] = -1;
        }
        
        return blueDistance;
    }
};