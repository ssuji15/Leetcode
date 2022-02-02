class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1},
                                      {1,1}, {1,0}, {1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        
        queue<vector<int>> q;
        q.push({0,0});

        if(grid[0][0] == 1) return -1;
        else visited[0][0] = 1;
        
        while(!q.empty()) {
            
            vector<int> temp = q.front();
            q.pop();
            
            int i = temp[0];
            int j = temp[1];
            int val = visited[i][j];
            
            if(grid[i][j] == 1) continue;
            
            for(int k=0;k<directions.size();k++) {
                int newI = i + directions[k][0];
                int newJ = j + directions[k][1];

                if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size()
                   && grid[newI][newJ] != 1 && val+1 < visited[newI][newJ]) {

                        visited[newI][newJ] = val+1;

                        if(newI == grid.size()-1 && newJ == grid[0].size()-1) {
                            return val+1;
                        }

                        q.push({newI, newJ});
                }
            }
        }
        
        int ans = visited[grid.size()-1][grid[0].size()-1];
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};