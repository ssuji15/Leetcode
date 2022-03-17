class Solution {
public:
    int count = 0;
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    void dfs(int i, int j, vector<vector<int>> &grid) {
        grid[i][j] = 0;
        count++;
        for(int k=0;k<directions.size();k++) {
            int newI = i + directions[k][0];
            int newJ = j + directions[k][1];
            if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() && grid[newI][newJ] == 1) {
                dfs(newI, newJ, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    count = 0;
                    dfs(i,j,grid);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};