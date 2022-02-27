class Solution {
public:
    vector<vector<int>> directions = {{}, {0,1}, {0,-1}, {1,0}, {-1,0}};
    
    
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> cost(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        vector<vector<bool>> inQueue(grid.size(), vector<bool>(grid[0].size(), false));
        queue<vector<int>> q;
        q.push({0,0});
        cost[0][0] = 0;
        inQueue[0][0] = true;
        while(!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();
            
            inQueue[i][j] = false;
            
            if(i == grid.size()-1 && j == grid[0].size()-1) {
                continue;
            }
            
            for(int k=1;k<directions.size();k++) {
                int newI = i + directions[k][0];
                int newJ = j + directions[k][1];
                
                if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size()) {
                    int newCost = cost[i][j];
                    if(grid[i][j] != k) {
                        newCost++;
                    }
                    
                    if(cost[newI][newJ] > newCost) {
                        cost[newI][newJ] = newCost;
                        if(!inQueue[newI][newJ]) {
                            q.push({newI,newJ});
                            inQueue[newI][newJ] = true;
                        }
                    }
                }
            }
        }
        
        
        return cost[grid.size()-1][grid[0].size()-1];
    }
};