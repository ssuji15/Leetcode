class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> distance(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        queue<vector<int>> q;
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                if(mat[i][j] == 0) {
                    distance[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();
            
            for(int k=0;k<directions.size();k++) {
                int newI = i + directions[k][0];
                int newJ = j + directions[k][1];
                
                if(newI >= 0 && newI < mat.size() && newJ >= 0 && newJ < mat[0].size() && 1+distance[i][j] < distance[newI][newJ]) {
                    distance[newI][newJ] = 1 + distance[i][j];
                    q.push({newI, newJ});
                }
            }
        }
        return distance;
    }
};