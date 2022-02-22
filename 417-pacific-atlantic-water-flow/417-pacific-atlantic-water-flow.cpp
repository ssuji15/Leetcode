class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    
    void bfs(queue<pair<int,int>> &q, unordered_map<int,unordered_map<int,int>> &visited,
            vector<vector<int>>& heights) {
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int k=0;k<directions.size();k++) {
                int newI = i + directions[k][0];
                int newJ = j + directions[k][1];
                
                if(newI >= 0 && newI < heights.size() && newJ >= 0 
                   && newJ <  heights[0].size() && !visited[newI][newJ] 
                   && heights[i][j] <= heights[newI][newJ]) {
                    visited[newI][newJ] = true;
                    q.push({newI, newJ});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        unordered_map<int,unordered_map<int,int>> visited1; 
        unordered_map<int,unordered_map<int,int>> visited2;
        queue<pair<int,int>> q;

        for(int i=0;i<heights.size();i++) {
            q.push({i,0});
            visited1[i][0] = true;
        }
        for(int i=0;i<heights[0].size();i++) {
            q.push({0,i});
            visited1[0][i] = true;
        }
        
        bfs(q,visited1,heights);
        
        for(int i=0;i<heights.size();i++) {
            q.push({i,heights[0].size()-1});
            visited2[i][heights[0].size()-1] = true;
        }
        
        for(int i=0;i<heights[0].size();i++) {
            q.push({heights.size()-1, i});
            visited2[heights.size()-1][i] = true;
        }
        bfs(q,visited2,heights);
        
        vector<vector<int>> result;
        for(int i=0;i<heights.size();i++) {
            for(int j=0;j<heights[0].size();j++) {
                if(visited1[i][j] && visited2[i][j]) {
                    result.push_back({i,j});
                }
            }
        }
        
        return result;
    }
};