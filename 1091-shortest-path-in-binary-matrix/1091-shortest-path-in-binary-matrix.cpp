class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        queue<vector<int>> q;
        if(grid[0][0] == 0) {
            distance[0][0] = 1;
            q.push({0,0});
        }
        while(!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();
            
            for(int k=0;k<directions.size();k++) {
                int newI = i + directions[k][0];
                int newJ = j + directions[k][1];
                
                if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() && distance[newI][newJ] > 1 + distance[i][j] && grid[newI][newJ] == 0) {
                    distance[newI][newJ] = 1 + distance[i][j];
                    q.push({newI,newJ});
                }
            }
        }
        int ans = distance[grid.size()-1][grid[0].size()-1];
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
};