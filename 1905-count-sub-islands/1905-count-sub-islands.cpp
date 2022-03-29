class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    bool dfs(int i, int j, vector<vector<int>> & grid2, vector<vector<int>> &grid1) {
        bool valid = grid1[i][j] == 1;
        grid2[i][j] = 0;
        for(int k=0;k<directions.size();k++) {
            int newI = i + directions[k][0];
            int newJ = j + directions[k][1];
            
            if(newI >= 0 && newI < grid2.size() && newJ >= 0 && newJ < grid2[0].size()
               && grid2[newI][newJ] == 1) {
                valid = valid & dfs(newI, newJ, grid2, grid1);
            }
        }
        return valid;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        for(int i=0;i<grid2.size();i++) {
            for(int j=0;j<grid2[0].size();j++) {
                if(grid2[i][j] == 1) {
                    if(dfs(i,j,grid2,grid1)) count++; 
                }
            }
        }
        return count;
    }
};