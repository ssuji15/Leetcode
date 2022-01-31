class Solution {
public:
    void dfs(int i, vector<vector<int>> &isConnected, unordered_map<int,bool> &visited) {
        for(int j=0;j<isConnected[i].size();j++) {
            if(isConnected[i][j] == 1 && visited.find(j) == visited.end()) {
                visited[j] = true;
                dfs(j, isConnected, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool> visited;
        int count = 0;
        for(int i=0;i<isConnected.size();i++) {
            if(visited.find(i) == visited.end()) {
                visited[i] = true;
                dfs(i, isConnected, visited);
                count++;
            }
        }
        
        return count;
    }
};