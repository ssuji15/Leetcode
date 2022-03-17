class Solution {
public:
    vector<int> leftMost;
    vector<int> rightMost;
    vector<int> topMost;
    vector<int> bottomMost;
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    bool dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        visited[i][j] = true;
        bool allTrue = true;
        for(int k=0;k<directions.size();k++) {
            int newI = i + directions[k][0];
            int newJ = j + directions[k][1];
            
            if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size()
              && grid[newI][newJ] == 0 && !visited[newI][newJ]) {
                if(!dfs(newI, newJ, grid, visited)) {
                    allTrue = false;
                }
            }
        }
        return allTrue && leftMost[i] < j && rightMost[i] > j && topMost[j] < i && bottomMost[j] > i;
    }
    int closedIsland(vector<vector<int>>& grid) {
        leftMost = vector<int>(grid.size(), INT_MAX);
        rightMost = vector<int>(grid.size(), -1);
        topMost = vector<int>(grid[0].size(), INT_MAX);
        bottomMost = vector<int>(grid[0].size(), -1);
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    topMost[j] = min(topMost[j], i);
                    leftMost[i] = min(leftMost[i], j);
                    rightMost[i] = max(rightMost[i], j);
                    bottomMost[j] = max(bottomMost[j], i);
                }
            }
        }
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 0 && !visited[i][j]) {
                    if(dfs(i,j, grid, visited)) {
                        count++;
                    }
                }
                
            }
        }
        
        return count;
        
    }
};