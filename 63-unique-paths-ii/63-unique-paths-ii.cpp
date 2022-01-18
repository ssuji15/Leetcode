class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        vector<vector<int>> grid(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        grid[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        
        for(int i=1;i<grid.size();i++) {
            grid[i][0] = obstacleGrid[i][0] == 1 ? 0 : grid[i-1][0];
        }
        
        for(int i=1;i<grid[0].size();i++) {
            grid[0][i] = obstacleGrid[0][i] == 1 ? 0 : grid[0][i-1];
        }
        
        for(int i=1;i<grid.size();i++) {
            for(int j=1;j<grid[0].size();j++) {
                int val1 = 0, val2 = 0;
                
                if(obstacleGrid[i][j] == 0) {
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }
            }
        }
        
        return grid[grid.size()-1][grid[0].size()-1];
        
    }
};