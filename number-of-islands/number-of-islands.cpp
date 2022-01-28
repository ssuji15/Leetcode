class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};

    void bfs(int i, int j, vector<vector<char>>& grid) {
        for(int k=0;k<directions.size();k++) {
            int newI = i+directions[k][0];
            int newJ = j+directions[k][1];
            
            if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() && grid[newI][newJ] == '1') {
                grid[newI][newJ] = '0';
                bfs(newI, newJ, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '0';
                    bfs(i,j,grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};