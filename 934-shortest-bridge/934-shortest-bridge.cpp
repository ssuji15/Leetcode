class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    void updateGrid(int i, int j, vector<vector<int>> &grid, queue<vector<int>> &q) {
        q.push({i,j});
        grid[i][j] = 2;
        for(int k=0;k<directions.size();k++) {
            int newI = i + directions[k][0];
            int newJ = j + directions[k][1];
            
            if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() 
               && grid[newI][newJ] == 1) {
                updateGrid(newI, newJ, grid, q);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        for(int i=0;q.size() == 0 && i<grid.size();i++) {
            for(int j=0;q.size() == 0 && j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    updateGrid(i,j,grid,q);
                }
            }
        }
        while(!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();
            for(int k=0;k<directions.size();k++) {
                int newI = directions[k][0] + i;
                int newJ = directions[k][1] + j;
                if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size()) {
                    if(grid[newI][newJ] == 1) {
                        return grid[i][j] - 2;
                    }
                    if(grid[newI][newJ] == 0) {
                        grid[newI][newJ] = grid[i][j] + 1;
                        q.push({newI, newJ});
                    }
                }
            }
        }
        return -1;
    }
};
