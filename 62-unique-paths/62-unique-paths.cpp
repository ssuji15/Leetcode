class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for(int i=0;i<grid.size();i++) {
            grid[i][0] = 1;
        }
        
        for(int i=0;i<grid[0].size();i++) {
            grid[0][i] = 1;
        }
        
        for(int i=1;i<grid.size();i++) {
            for(int j=1;j<grid[0].size();j++) {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        
        return grid[m-1][n-1];
    }
};