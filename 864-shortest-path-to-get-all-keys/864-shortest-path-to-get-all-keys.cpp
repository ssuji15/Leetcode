class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    int shortestPathAllKeys(vector<string>& grid) {
        int ans = INT_MAX;
        queue<vector<int>> q;
        int maxKey = 0;
        vector<vector<vector<int>>> visited(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(64, false)));
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == '@') {
                    q.push({i,j,0,0});
                    visited[i][j][0] = true;
                }
                
                if(grid[i][j] >= 'A' && grid[i][j] <= 'F') {
                    maxKey++;
                }
            }
        }
        
        int value = 1;
        for(int i=0;i<maxKey;i++) {
            value *= 2;
        }
        
        while(!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            int count = q.front()[2];
            int keys = q.front()[3];
            q.pop();
           //cout<<i<<" "<<j<<" "<<count<<" "<<keys<<endl;
            
            if(grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                keys = keys | (1 << (grid[i][j]-'a'));
            }
            else if(grid[i][j] >= 'A' && grid[i][j] <= 'F') {
                if((keys & (1 << (grid[i][j]-'A'))) == 0) continue;
            }
            
            if(keys == value-1) {
                ans = min(ans, count);
                break;
            }

            for(int k=0;k<directions.size(); k++) {
                int newI = i + directions[k][0];
                int newJ = j + directions[k][1];
                
                if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() && !visited[newI][newJ][keys] && grid[newI][newJ] != '#') {
                    q.push({newI, newJ, count+1, keys});
                    visited[newI][newJ][keys] = true;
                }
            }
        }
        if(ans == INT_MAX) ans=-1;
        return ans;
    }
};
