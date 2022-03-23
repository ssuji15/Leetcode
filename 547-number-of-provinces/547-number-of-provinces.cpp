class Solution {
public:
    void dfs(int idx, vector<bool> &visited, vector<vector<int>> &isConnected) {
        visited[idx] = true;
        for(int i=0;i<isConnected[idx].size();i++) {
            if(!visited[i] && isConnected[idx][i] == 1) {
                dfs(i, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int count = 0;
        for(int i=0;i<isConnected.size();i++) {
            if(!visited[i]) {
                count++;
                dfs(i,visited,isConnected);
            }
        }
        return count;
    }
};