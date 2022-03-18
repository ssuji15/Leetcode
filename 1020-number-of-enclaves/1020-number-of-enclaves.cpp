class Solution {
public:
    vector<int> leftMost, rightMost, topMost, bottomMost;
    vector<vector<bool>> visited;
    vector<vector<int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
    int count;
    bool dfs(int i, int j, vector<vector<int>> &grid) {
        visited[i][j] = true;
        count++;
        bool canReach = false;
        for(int k=0;k<directions.size();k++) {
            int newI = i + directions[k][0];
            int newJ = j + directions[k][1];
            if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() 
               && !visited[newI][newJ] && grid[newI][newJ] == 1) {
                if(dfs(newI, newJ, grid)) {
                    canReach = true;
                }
            }
        }
        
        return canReach || leftMost[i] > j || rightMost[i] < j || topMost[j] > i || bottomMost[j] < i;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        leftMost = vector<int>(grid.size(), INT_MAX);
        rightMost = vector<int>(grid.size(), -1);
        topMost = vector<int>(grid[0].size(), INT_MAX);
        bottomMost = vector<int>(grid[0].size(), -1);
        int ans = 0;
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 0) {
                    leftMost[i] = min(leftMost[i], j);
                    rightMost[i] = max(rightMost[i],j);
                    topMost[j] = min(topMost[j], i);
                    bottomMost[j] = max(bottomMost[j], i);
                }
            }
        }
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    count = 0;
                    if(!dfs(i,j,grid)) {
                      ans += count;  
                    };
                }
            }
        }
        
        return ans;
        
    }
};