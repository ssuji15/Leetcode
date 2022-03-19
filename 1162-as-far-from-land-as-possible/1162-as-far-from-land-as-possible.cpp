class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1},{1,0}};
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        queue<vector<int>> q;
        int ans = INT_MIN;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    distance[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();
            
            for(int k=0;k<directions.size();k++) {
                int newI = i + directions[k][0];
                int newJ = j + directions[k][1];
                
                if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() 
                   && (1 + distance[i][j] < distance[newI][newJ])) {
                    distance[newI][newJ] = 1 + distance[i][j];
                    ans = max(ans, distance[newI][newJ]);
                    q.push({newI, newJ});
                }
            }
        }
        if(ans == INT_MIN) ans = -1;
        return ans;
    }
};