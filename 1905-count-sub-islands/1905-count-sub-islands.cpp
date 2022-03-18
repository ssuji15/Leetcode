class Solution {
public:
    vector<vector<int>> island;
    vector<vector<bool>> visited;
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    void dfs(int i, int j, vector<vector<int>> &grid) {
        visited[i][j] = true;
        island.push_back({i,j});
        for(int k=0;k<directions.size();k++) {
            int newI = i + directions[k][0];
            int newJ = j + directions[k][1];
            if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() && !visited[newI][newJ] && grid[newI][newJ] == 1) {
                dfs(newI, newJ, grid);
            }
        }
    }
    bool valid(vector<vector<int>> &grid) {
        bool isValid = true;
        for(int i=0;i<island.size();i++) {
            if(grid[island[i][0]][island[i][1]] == 0) {
                isValid = false;
                break;
            }
        }
        return island.size() > 0 && isValid;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        island = {};
        visited = vector<vector<bool>>(grid2.size(), vector<bool>(grid2[0].size(), false));
        for(int i=0;i<grid2.size();i++) {
            for(int j=0;j<grid2[0].size();j++) {
                if(grid2[i][j] == 1 && !visited[i][j]) {
                    island = {};
                    dfs(i,j,grid2);
                    if(valid(grid1)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};