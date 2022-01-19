class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                int val1 = INT_MAX, val2 = INT_MAX;
                if(i-1 >= 0) {
                    val1 = grid[i-1][j];
                }
                if(j-1 >= 0) {
                    val2 = grid[i][j-1];
                }
                
                if(val1 == INT_MAX && val2 == INT_MAX) continue;
                grid[i][j] += min(val1, val2);
            }
        }
        
        return grid[grid.size()-1][grid[0].size()-1];
    }
};